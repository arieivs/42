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

int	count_commands(int instruction_size, char **av)
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
}

int	cd(char **av, char **envp)
{
	(void)av;
	(void)envp;
	printf("I'm in cd\n");
	return (0);
}

int	execute_in_child(char **av, char **envp)
{
	(void)av;
	(void)envp;
	printf("I'm in parent to have a child\n");
	exit(0);
	return (0);
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
	int		exit_code = 0; // makes sense?

	(void)envp;

	while (i < instruction_size)
	{
		command_size = end_segment(i, instruction_size, av, "|");
		fd_in = fd_in_next;
		fd_out = 1;
		if (i + command_size < instruction_size) /* if there's a next command */
		{
			if (pipe(fds_pipe) == -1)
				exit(1); // make error function and display message
			fd_out = fds_pipe[1];
			fd_in_next = fds_pipe[0];
		}
		if (strcmp("cd", av[i]) == 0) /* cd will only be run as a single command */
			exit_code = cd(av + i, envp);
		else
		{
			pid = fork();
			if (pid == 0)
				exit_code = execute_in_child(av + i, envp);
			else
				waitpid(pid, NULL, 0);
		}
		if (fd_in != 0)
			close(fd_in);
		if (fd_out != 1 && close(fd_out) == -1)
			exit(1); // make error function and display message
		i = i + command_size + 1;
	}
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	instruction_size;
	int	nb_commands;

	// check user input?
	i = 1; /* cos executable name doesn't count */
	while (i < ac)
	{
		instruction_size = end_segment(i, ac, av, ";");
		nb_commands = count_commands(instruction_size, av + i);
		printf("instruction size %d nb commands %d\n", instruction_size, nb_commands);
		execute_instruction(instruction_size, av + i, envp);
		i = i + instruction_size + 1;
	}
	return (0);
}
