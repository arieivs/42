#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int main(void)
{
	int nb = 2;
	int power = 4;
	int result;

	result = ft_recursive_power(nb, power);
	printf("%d^%d = %d\n", nb, power, result);
	return (0);
}
