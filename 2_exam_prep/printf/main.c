#include <stdio.h>

int	ft_printf(char *str, ...);

int	main(void)
{
	int mine;
	int	orgn;

	mine = ft_printf("hello %s %x %d %d\n", "stranger", -42, 0, -0123);
	orgn = printf("hello %s %x %d %d\n", "stranger", -42, 0, -0123);
	printf("mine: %d original: %d\n", mine, orgn);
	return (0);
}
