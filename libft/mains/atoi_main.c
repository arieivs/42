#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char	x[] = "  \n  0325 6";
	char	y[] = "  \t -870abc";
	char	z[] = "  ++89-";

	printf("\nATOI\n");
	printf("1 - orgn: %d\n", atoi(x));
	printf("    mine: %d\n", ft_atoi(x));
	printf("2 - orgn: %d\n", atoi(y));
	printf("    mine: %d\n", ft_atoi(y));
	printf("3 - orgn: %d\n", atoi(z));
	printf("    mine: %d\n", ft_atoi(z));

	return (0);
}
