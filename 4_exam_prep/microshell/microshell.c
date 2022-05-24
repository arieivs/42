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

int	execute_instruction(int instruction_size, char **av, char **envp)
{
	int	i = 0;
	int	nb_commands;
	int	command_size;
	(void)envp;

	nb_commands = count_commands(instruction_size, av);
	printf("nb commands %d\n", nb_commands);
	while (i < instruction_size)
	{
		command_size = end_segment(i, instruction_size, av, "|");
		//execute command
		i = i + command_size + 1;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	instruction_size;

	// check user input?
	i = 1; /* cos executable name doesn't count */
	while (i < ac)
	{
		instruction_size = end_segment(i, ac, av, ";");
		printf("instruction size %d ", instruction_size);
		execute_instruction(instruction_size, av + i, envp);
		i = i + instruction_size + 1;
	}
	return (0);
}
