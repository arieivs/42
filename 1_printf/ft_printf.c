/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:34:01 by svieira           #+#    #+#             */
/*   Updated: 2021/03/31 17:00:13 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	fmt->left_align = 0;
	fmt->fill = ' ';
	fmt->plus = 0;
	fmt->hash = 0;
	fmt->width = 0;
	fmt->point = 0;
	fmt->precision = 0;
	fmt->conv = 0;
	return (fmt);
}

int		str_include(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	parse_flags(char flag, t_fmt *fmt)
{
	if (flag == '-')
	{
		fmt->left_align = 1;
		printf("left ");
	}
	if (!fmt->left_align && flag == '0') // - wins over 0
	{
		fmt->fill = '0';
		printf("zero ");
	}
	if (flag == '+')
	{
		fmt->plus = '+';
		printf("plus ");
	}
	if (!fmt->plus && flag == ' ') // + wins over space
	{
		fmt->plus = ' ';
		printf("space ");
	}
	if (flag == '#')
	{
		fmt->hash = 1;
		printf("hash ");
	}
}

int		parse(char *str, t_fmt *fmt, va_list ap)
{
	int		i;

	i = 0;
	while (str_include("-0+ #", str[i]))
		parse_flags(str[i++], fmt);
	if (str[i] == '*' && str[i++]) // width is given as an argument
		fmt->width = va_arg(ap, int);
	if (fmt->width < 0) // if width is negative, take - as if it was a flag
	{
		fmt->width *= -1;
		fmt->left_align = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		fmt->width = fmt->width * 10 + (str[i++] - '0');
	printf("width %d ", fmt->width);
	if (str[i] == '.' && str[i++])
	{
		fmt->point = 1;
		printf("precision is here! ");
	}
	if (str[i] == '*' && str[i++]) // precision is given as an argument
		fmt->precision = va_arg(ap, int);
	if (fmt->precision < 0) // if precision is negative, ignore the .
	{
		fmt->point = 0;
		fmt->precision = 0;
	}
	while (str[i] >= '0' && str[i] <= '9')
		fmt->precision = fmt->precision * 10 + (str[i++] - '0');
	printf("precision %d ", fmt->precision);
	if (str_include("cspdiuxX", str[i]))
		fmt->conv = str[i++];
	printf("conversion %c", fmt->conv);
	return (i);
}

int		print_fmt(t_fmt *fmt, va_list ap)
{
	int	printed;

	printed = 0;
	if (fmt->conv == 'd')
		printed = d_print(fmt, ap);
	
	return (printed);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		printed;
	t_fmt	*fmt;

	va_start(ap, str);
	i = 0;
	printed = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printed++;
			if (str[i] == '%')
			{
				write(1, "%", 1);
				i++;
				printed++;
				continue ;
			}
			fmt = init_fmt();
			i += parse(str + i, fmt, ap);
			printed += print_fmt(fmt, ap);
			free(fmt);
			continue ;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (printed);
}

int	main(void)
{
	//ft_putstr("I like \'100\\ \a \b \f \r \t \v discounts\n");
	printf("I like you %-+*.*dtoo\n", 4, 4, -5982);
	//printf("I like you %*d too\n", 10, 5982);
	//iter_str("100%+ -05 -40%%discount % 0+-mm\n");
	//ft_printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	ft_printf("hey %-+4.4d", -5982);
	return (0);
}
