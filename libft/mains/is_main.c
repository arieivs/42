#include <ctype.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int i;
	int	c;

	i = 1;
	while (i < ac)
	{
		c = av[i][0];
		printf("isalpha %c is ", av[i][0]);
		if (isalpha(c))
			printf("ALPHA\n");
		else
			printf("NOT ALPHA\n");
		printf("ft_isalpha %c is ", av[i][0]);
		if (isalpha(c))
			printf("ALPHA\n\n");
		else
			printf("NOT ALPHA\n\n");
		i++;
	}
	return (0);
}
