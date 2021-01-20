#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char *base_to = "0123456789";
	char *nbr = "  -+--2147483648def";
	char *base_from = "0123456789";
	char *result;

	result = ft_convert_base(nbr, base_from, base_to);
	printf("%s.\n", result);
	return (0);
}
