#include <stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	int nb = 3136;
	int sqrt;

	sqrt = ft_sqrt(nb);
	printf("sqrt(%d) = %d\n", nb, sqrt);
	return (0);
}
