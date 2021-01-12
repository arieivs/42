#include <stdio.h>

int	ft_is_prime(int nb);

int main(void)
{
	int nb = 853;

	if (ft_is_prime(nb))
		printf("%d is prime\n", nb);
	else
		printf("%d is not prime\n", nb);
	return (0);
}
