/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:34:01 by svieira           #+#    #+#             */
/*   Updated: 2021/03/29 19:52:17 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_fmt	*init_fmt(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)malloc(sizeof(t_fmt));
	fmt->plus = 0;
	fmt->left_align = 0;
	fmt->fill = ' ';
	fmt->width = 0;
	fmt->point = 0;
	fmt->precision = 0;
	fmt->conv = 0;
	return (fmt);
}

int		parse(char *str, t_fmt *fmt, va_list ap)
{
	int		i;

	i = 0;
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
	if (str[i] == '*' && str[i++])
		fmt->width = va_arg(ap, int);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->width = fmt->width * 10 + (str[i++] - '0');
	printf("width %d ", fmt->width);
	if (str[i] == '.' && str[i++])
	{
		fmt->point = 1;
		printf("precision is here! ");
	}
	if (str[i] == '*' && str[i++])
		fmt->precision = va_arg(ap, int);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->precision = fmt->precision * 10 + (str[i++] - '0');
	printf("precision %d ", fmt->precision);
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		fmt->conv = str[i++];
	printf("conversion %c", fmt->conv);
	return (i);
}

//int		print_fmt(t_list *fmt, va_list ap)
//{

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
			//printed += print_fmt(fmt, ap);
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
	//printf("I like you %.2-5f too\n", 4.756);
	//iter_str("100%+ -05 -40%%discount % 0+-mm\n");
	ft_printf("hey %+-*.*d\n", 589, 600);
	return (0);
}
