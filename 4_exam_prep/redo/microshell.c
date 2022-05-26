#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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

int	execute_instruction(int instruction_size, char **av, char **envp)
{
	int	i = 0;
	int	command_size = 0;
	(void)envp;
	
	while (i < instruction_size)
	{
		command_size = end_segment(i, instruction_size, av, "|");
		printf("command_size %d\n", command_size);
		i = i + command_size + 1;
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int	i = 1; // cos executable name is not relevant
	int	instruction_size = 0;
	int	exit_code;

	while (i < ac)
	{
		instruction_size = end_segment(i, ac, av, ";");
		printf("instruction size %d\n", instruction_size);
		exit_code = execute_instruction(instruction_size, av + i, envp);
		i = i + instruction_size + 1;
	}
	return (exit_code);
}
