#include <stdio.h>

int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int nb_solutions;

	nb_solutions = ft_ten_queens_puzzle();
	printf("found %d solutions for the Ten Queens puzzle\n", nb_solutions);
	return (0);
}
