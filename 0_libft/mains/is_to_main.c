#include <ctype.h>
#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	int		i;
	char	is[] = "a0[ ";
	char	bel = 7;
	char	to[] = "abRa C4D58rA";
	char	x[] = "  \n  0325 6";
	char	y[] = "  \t -870abc";
	char	z[] = "  ++89-";

	i = 0;
	printf("\nIS\n");
	while (is[i])
	{
		printf("%d - orgnl: %c is ", i + 1, is[i]);
		if (isalpha(is[i]))
			printf("ALPHA ");
		if (isdigit(is[i]))
			printf("DIGIT ");
		if (isalnum(is[i]))
			printf("Alphanumeric ");
		if (isascii(is[i]))
			printf("ASCII ");
		printf("\n");

		printf("    my ft: %c is ", is[i]);
		if (ft_isalpha(is[i]))
			printf("ALPHA ");
		if (ft_isdigit(is[i]))
			printf("DIGIT ");
		if (ft_isalnum(is[i]))
			printf("Alphanumeric ");
		if (ft_isascii(is[i]))
			printf("ASCII ");
		printf("\n\n");
		i++;
	}
	printf("%d - orgnl: bel is ", i + 1);
	if (!isprint(bel))
		printf("non printable\n");
	printf("    my ft: bel is ");
	if (!ft_isprint(bel))
		printf("non printable\n");

	printf("\nTOUPPER\norgnl: ");
	i = 0;
	while (to[i])
	{
		printf("%c", toupper(to[i]));
		i++;
	}
	printf("\nmy ft: ");
	i = 0;
	while (to[i])
	{
		printf("%c", ft_toupper(to[i]));
		i++;
	}

	printf("\n\nTOLOWER\norgnl: ");
	i = 0;
	while (to[i])
	{
		printf("%c", tolower(to[i]));
		i++;
	}
	printf("\nmy ft: ");
	i = 0;
	while (to[i])
	{
		printf("%c", ft_tolower(to[i]));
		i++;
	}
	printf("\n");

	printf("\nATOI\n");
	printf("1 - orgn: %d\n", atoi(x));
	printf("    mine: %d\n", ft_atoi(x));
	printf("2 - orgn: %d\n", atoi(y));
	printf("    mine: %d\n", ft_atoi(y));
	printf("3 - orgn: %d\n", atoi(z));
	printf("    mine: %d\n", ft_atoi(z));

	printf("\nITOA\n");
	printf("1 - i: %d, a: %s\n", 0, ft_itoa(0));
	printf("2 - i: %d, a: %s\n", 3510, ft_itoa(3510));
	printf("3 - i: %ld, a: %s\n\n", -2147483648, ft_itoa(-2147483648));
	return (0);
}
