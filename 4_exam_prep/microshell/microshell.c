#include "microshell.h"

int	end_segment(int start, int end, char **av, char *delimiter)
{
	int	size = 0;

	while (start + size < end)
	{
		if (strcmp(av[start + size], delimiter) == 0)
		{
			av[start + size] = NULL;
			return (size);
		}
		size++;
	}
	return (size);
}

// for testing purposes:
/*int	count_commands(int instruction_size, char **av)
{
	int i = 0;
	int	nb_commands = 0;

	while (i < instruction_size)
	{
		if (strcmp(av[i], "|") == 0)
			nb_commands++;
		i++;
	}
	if (av[instruction_size - 1] && strcmp(av[instruction_size - 1], "|")) 
		nb_commands++;
	return (nb_commands);
}*/

int	cd(char **args)
{
	int	nb_args = 0;
	int	arg_len = 0;
	
	while (args[nb_args])
		nb_args++;
	if (nb_args == 0) /* not throwing an error with nb_args > 1 */
	{
		write(STDERR_FILENO, "error: cd: bad arguments\n", 25);
		return (1);
	}
	if (chdir(args[0]) == -1)
	{
		write(STDERR_FILENO, "error: cd: cannot change directory to ", 38);
		while (args[0][arg_len])
			arg_len++;
		write(STDERR_FILENO, args[0], arg_len);
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}

void	execute_in_child(char **av, char **envp, int fd_in, int fd_out)
{
	int	cmd_name_len = 0;

	if (fd_in != 0)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != 1)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	execve(av[0], av, envp);
	write(STDERR_FILENO, "error: cannot execute ", 22);
	while (av[0][cmd_name_len])
		cmd_name_len++;
	write(STDERR_FILENO, av[0], cmd_name_len);
	write(STDERR_FILENO, "\n", 1);
	exit(127); /* If execve didn't run, the command doesn't exist */
}

void	error_and_exit(void)
{
	write(STDERR_FILENO, "error: fatal\n", 13);
	exit(1);
}

int	execute_instruction(int instruction_size, char **av, char **envp)
{
	int		i = 0;
	int		command_size;
	int		fd_in = 0;
	int 	fd_out = 1;
	int		fd_in_next = 0;
	int		fds_pipe[2];
	pid_t	pid;
	int		status;
	int		exit_code = 0;

	while (i < instruction_size)
	{
		//printf("executing\n");
		command_size = end_segment(i, instruction_size, av, "|");
		fd_in = fd_in_next;
		fd_out = 1;
		if (i + command_size < instruction_size) /* if there's a next command */
		{
			if (pipe(fds_pipe) == -1)
				error_and_exit();
			fd_out = fds_pipe[1];
			fd_in_next = fds_pipe[0];
		}
		if (strcmp("cd", av[i]) == 0) /* cd will only be run as a single command */
			exit_code = cd(av + i + 1); /* pointing at its first argument */
		else
		{
			pid = fork();
			if (pid == -1)
				error_and_exit();
			if (pid == 0)
				execute_in_child(av + i, envp, fd_in, fd_out);
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					exit_code = WEXITSTATUS(status);
			}
		}
		if (fd_in != 0 && close(fd_in))
			error_and_exit();
		if (fd_out != 1 && close(fd_out) == -1)
			error_and_exit();
		i = i + command_size + 1;
	}
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	instruction_size;
	//int	nb_commands;
	int	exit_code;

	// check user input?
	i = 1; /* cos executable name doesn't count */
	while (i < ac)
	{
		instruction_size = end_segment(i, ac, av, ";");
		//nb_commands = count_commands(instruction_size, av + i);
		//printf("instruction size %d nb commands %d\n", instruction_size, nb_commands);
		exit_code = execute_instruction(instruction_size, av + i, envp);
		i = i + instruction_size + 1;
	}
	return (exit_code);
}
