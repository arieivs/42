#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//#include <stdio.h>

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

void	error_and_exit(void)
{
	write(STDERR_FILENO, "error: fatal\n", 13);
	exit(1);
}

int	cd(char **args)
{
	int	nb_args = 0;
	int	path_len = 0;

	while (args[nb_args])
		nb_args++;
	if (nb_args == 0)
	{
		write(STDERR_FILENO, "error: cd: bad arguments\n", 25);
		return (1);
	}
	if (chdir(args[0]) == -1)
	{
		write(STDERR_FILENO, "error: cd: cannot change directory to ", 38);
		while (args[0][path_len])
			path_len++;
		write(STDERR_FILENO, args[0], path_len);
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	return (0);
}

void	execute_in_child(int fd_in, int fd_out, char **args, char **envp)
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
	execve(args[0], args, envp);
	write(STDERR_FILENO, "error: cannot execute ", 22);
	while (args[0][cmd_name_len])
		cmd_name_len++;
	write(STDERR_FILENO, args[0], cmd_name_len);
	write(STDERR_FILENO, "\n", 1);
}

int	execute_instruction(int instruction_size, char **av, char **envp)
{
	int		i = 0;
	int		command_size = 0;
	int		fd_in = 0;
	int		fd_out = 1;
	int		fd_in_next = 0;
	int		fds_pipe[2];
	pid_t	pid;
	int		status;
	int		exit_code = 0;
	
	while (i < instruction_size)
	{
		command_size = end_segment(i, instruction_size, av, "|");
		//printf("command_size %d\n", command_size);
		fd_in = fd_in_next;
		fd_out = 1;
		if (i + command_size < instruction_size)
		{
			if (pipe(fds_pipe) == -1)
				error_and_exit();
			fd_out = fds_pipe[1];
			fd_in_next = fds_pipe[0];
		}
		//printf("fd in %d, fd out %d\n", fd_in, fd_out);
		if (strcmp("cd", av[0]) == 0)
			exit_code = cd(av + 1); // +1 to skip cd
		else
		{
			pid = fork();
			if (pid == -1)
				error_and_exit();
			if (pid == 0)
				execute_in_child(fd_in, fd_out, av + i, envp);
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
					exit_code = WEXITSTATUS(status);
			}
		}
		if (fd_in != 0 && close(fd_in) == -1)
			error_and_exit();
		if (fd_out != 1 && close(fd_out) == -1)
			error_and_exit();
		i = i + command_size + 1;
	}
	return (exit_code);
}

int main(int ac, char **av, char **envp)
{
	int	i = 1; // cos executable name is not relevant
	int	instruction_size = 0;
	int	exit_code;

	while (i < ac)
	{
		instruction_size = end_segment(i, ac, av, ";");
		//printf("instruction size %d\n", instruction_size);
		exit_code = execute_instruction(instruction_size, av + i, envp);
		i = i + instruction_size + 1;
	}
	return (exit_code);
}
