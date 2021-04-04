#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	var_ft(char *str, ...)
{
	int		i = 0;
	va_list	pa;
	char	c;
	char	*s;
	void	*p;
	unsigned long	mem;

	va_start(pa, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				c = va_arg(pa, int);
				write(1, &c, 1);
			}
			else if (str[i] == 's')
			{
				s = va_arg(pa, char *);
				ft_putstr(s);
			}
			else if (str[i] == 'p')
			{
				p = va_arg(pa, void *);
				mem = (unsigned long)p;
				printf("\nadd: %p my way: %#lx\n", (void *)p, mem);
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(pa);
}

int	main(void)
{
	char	a = 'a';
	var_ft("hel%co %s%pess\n", 'l', "dark", &a);
	return (0);
}
