/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:37:18 by svieira           #+#    #+#             */
/*   Updated: 2021/04/05 10:43:09 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			str_include(char *str, char c)
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

static void	parse_flags(char flag, t_fmt *fmt)
{
	if (flag == '-') // - wins over 0
	{
		fmt->left_align = 1;
		fmt->fill = ' ';
	}
	if (!fmt->left_align && flag == '0')
		fmt->fill = '0';
	if (flag == '+')
		fmt->plus = '+';
	if (!fmt->plus && flag == ' ') // + wins over space
		fmt->plus = ' ';
	if (flag == '#')
		fmt->hash = 1;
}

static void	deal_neg_width(t_fmt *fmt)
{
	fmt->width *= -1;
	fmt->left_align = 1;
}

static void	deal_neg_preci(t_fmt *fmt)
{
	fmt->point = 0;
	fmt->precision = 0;
}

int			parse(const char *str, t_fmt *fmt, va_list ap)
{
	int		i;

	i = 0;
	while (str_include("-0+ #", str[i]))
		parse_flags(str[i++], fmt);
	if (str[i] == '*' && str[i++]) // width is given as an argument
		fmt->width = va_arg(ap, int);
	if (fmt->width < 0) // if width is negative, take - as if it was a flag
		deal_neg_width(fmt);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->width = fmt->width * 10 + (str[i++] - '0');
	if (str[i] == '.' && str[i++])
		fmt->point = 1;
	if (str[i] == '*' && str[i++]) // precision is given as an argument
		fmt->precision = va_arg(ap, int);
	if (fmt->precision < 0) // if precision is negative, ignore the .
		deal_neg_preci(fmt);
	while (str[i] >= '0' && str[i] <= '9')
		fmt->precision = fmt->precision * 10 + (str[i++] - '0');
	if (str_include("cspdiuxX%", str[i]))
		fmt->conv = str[i++];
	return (i);
}
