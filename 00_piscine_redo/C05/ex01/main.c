#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	int nb = 5;
	int factorial;

	factorial = ft_recursive_factorial(nb);
	printf("%d! = %d\n", nb, factorial);
	return (0);
}
