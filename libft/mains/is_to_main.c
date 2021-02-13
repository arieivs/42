#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

int	main(void)
{
	int		i;
	char	is[] = "a0[ ";
	char	bel = 7;
	char	to[] = "abRa C4D58rA";

	i = 0;
	printf("\nIS\n");
	while (is[i])
	{
		printf("orgnl: %c is ", is[i]);
		if (isalpha(is[i]))
			printf("ALPHA ");
		if (isdigit(is[i]))
			printf("DIGIT ");
		if (isalnum(is[i]))
			printf("Alphanumeric ");
		if (isascii(is[i]))
			printf("ASCII ");
		printf("\n");

		printf("my ft: %c is ", is[i]);
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
	printf("orgnl: bel is ");
	if (!isprint(bel))
		printf("non printable\n");
	printf("my ft: bel is ");
	if (!ft_isprint(bel))
		printf("non printable\n\n");

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
	return (0);
}
