/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:42:38 by svieira           #+#    #+#             */
/*   Updated: 2021/11/05 17:59:52 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

/*
 * prototype: int ft_printf(const char *, ... );
 * allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
 * manage conversions s, d and x
 */

static int	print_s(char *str)
{
	int	size;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = 0;
	while (str[size])
		 size++;
	write(1, str, size);
	return (size);
}

static void print_d_recursive(int nb)
{
	char c;

	if (nb == 0)
		return ;
	print_d_recursive(nb / 10);
	c = ((nb % 10) * -1) + '0';
	write(1, &c, 1);
}

static int	print_d(int nb)
{
	int		printed;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	printed = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		printed++;
	}
	if (nb > 0)
		nb *= -1; 
	print_d_recursive(nb);
	while (nb < 0)
	{
		nb = nb / 10;
		printed++;
	}
	return (printed);
}

static void	print_x_recursive(unsigned int nb)
{
	char	c;

	if (nb == 0)
		return ;
	print_x_recursive(nb / 16);
	c = "0123456789abcdef"[nb % 16];
	write(1, &c, 1);
}

static int	print_x(unsigned int nb)
{
	int	printed;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	printed = 0;
	print_x_recursive(nb);
	while (nb > 0)
	{
		nb = nb / 16;
		printed++;
	}
	return (printed);
}

static int print_flag(char flag, va_list ap)
{
	int	printed;

	printed = 0;
	if (flag == 's')
		printed = print_s(va_arg(ap, char*));
	if (flag == 'd')
		printed = print_d(va_arg(ap, int));
	if (flag == 'x')
		printed = print_x(va_arg(ap, unsigned int));
	return (printed);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	va_start(ap, str);
	i = 0;
	printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed += print_flag(str[++i], ap);
			i++;
			continue ;
		}
		write(1, &str[i], 1);
		printed++;
		i++;
	}
	va_end(ap);
	return (printed);
}

