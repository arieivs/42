#include <stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	int index = 7;
	int fib;

	fib = ft_fibonacci(index);
	printf("fibonacci's %dth number is %d\n", index, fib);
	return (0);
}
