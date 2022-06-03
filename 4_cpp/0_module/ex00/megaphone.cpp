#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (i = 1; i < ac; i++)
	{
		for (j = 0; j < strlen(av[i]); j++)
			putchar(toupper(av[i][j]));
	}
	std::cout << std::endl;
	return (0);
}
