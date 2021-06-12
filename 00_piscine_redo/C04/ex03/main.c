#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	char str[] = "   \n ---+--+1234ab567";
	int nb;

	nb = ft_atoi(str);
	printf("%d\n", nb);
	return (0);
}
