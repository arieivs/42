#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char base_to[5];
	//char *base_to = "01";
	char *nbr = "  -+--2147483648def";
	//char *nbr = "320";
	char *base_from = "0123456789";
	char *result;

	base_to[0] = 'p';
	base_to[1] = 'o';
	base_to[2] = 7;
	base_to[3] = 'e';
	base_to[4] = 'y';
	result = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", result);
	return (0);
}
