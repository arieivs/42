#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char str[] = "  \n --+helloooui";
	char base[] = "leoh";
	int nb;

	nb = ft_atoi_base(str, base);
	printf("%d\n", nb);
	return (0);
}
