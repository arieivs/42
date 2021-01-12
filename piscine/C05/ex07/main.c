#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	int nb = 2012;
	int next;

	next = ft_find_next_prime(nb);
	printf("the next prime >= %d is %d\n", nb, next);
	return (0);
}
