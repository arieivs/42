#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	main(int ac, char **av)
{
	int i;
	int	c;

	i = 1;
	while (i < ac)
	{
		c = av[i][0];
		printf("original: %c is ", av[i][0]);
		if (isalpha(c))
			printf("ALPHA\n");
		else if (isdigit(c))
			printf("DIGIT\n");
		else
			printf("a thing\n");
		printf("my ft: %c is ", av[i][0]);
		if (ft_isalpha(c))
			printf("ALPHA\n\n");
		else if (ft_isdigit(c))
			printf("DIGIT\n\n");
		else
			printf("a thing\n\n");
		i++;
	}
	return (0);
}
