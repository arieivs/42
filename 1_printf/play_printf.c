#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

typedef struct	s_fmt
{
	char	plus;
	int		left_align;
	char	fill;
	int		width;
}				t_fmt;

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	fmt->plus = 0;
	fmt->left_align = 0;
	fmt->fill = ' ';
	fmt->width = 0;
	return (fmt);
}

int	parse(char *str)
{
	int		i;
	t_fmt	*fmt;

	i = 0;
	fmt = init_fmt();
	while (str[i] == '+' || str[i] == ' ' || str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '+')
		{
			fmt->plus = '+';
			printf("plus ");
		}
		if (!fmt->plus && str[i] == ' ')
		{
			fmt->plus = ' ';
			printf("space ");
		}
		if (str[i] == '-')
		{
			fmt->left_align = 1;
			printf("left ");
		}
		if (!fmt->left_align && str[i] == '0')
		{
			fmt->fill = '0';
			printf("zero ");
		}
		i++;
	}
	free(fmt);
	return (i);
}

void	iter_str(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				write(1, "%", 1);
				i++;
				continue ;
			}
			i += parse(str + i);
			continue ;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	//ft_putstr("I like \'100\\ \a \b \f \r \t \v discounts\n");
	//printf("I like you %  - + 5d too\n", 4);
	iter_str("100%+ -05 -40%%discount % 0+-mm\n");
	return (0);
}
