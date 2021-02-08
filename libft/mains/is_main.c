#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);

int	main(int ac, char **av)
{
	int i;
	int	c;

	i = 1;
	while (i < ac)
	{
		c = av[i][0];

		printf("orgnl: %c is ", av[i][0]);
		if (isalpha(c))
			printf("ALPHA ");
		if (isdigit(c))
			printf("DIGIT ");
		if (isalnum(c))
			printf("Alphanumeric ");
		printf("\n");

		printf("my ft: %c is ", av[i][0]);
		if (ft_isalpha(c))
			printf("ALPHA ");
		if (ft_isdigit(c))
			printf("DIGIT ");
		if (ft_isalnum(c))
			printf("Alphanumeric ");
			printf("\n\n");
		i++;
	}
	return (0);
}
