/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:34:01 by svieira           #+#    #+#             */
/*   Updated: 2021/04/06 17:38:28 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	fmt->size = 0;
	fmt->conv = 0;
	return (fmt);
}

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

int		print_fmt(t_fmt *fmt, va_list ap, int printed)
{
	if (fmt->conv == 'c' || fmt->conv == '%')
		printed += c_print(fmt, ap);
	if (fmt->conv == 's')
		printed += s_print(fmt, ap);
	if (str_include("di", fmt->conv) && (!fmt->size || fmt->size == 'H'))
		printed += di_print(fmt, ap);
	if (str_include("di", fmt->conv) && fmt->size == 'h')
		printed += dih_print(fmt, ap);
	if (str_include("di", fmt->conv) && fmt->size == 'L')
		printed += dill_print(fmt, ap);
	if (str_include("uxX", fmt->conv) && (!fmt->size || fmt->size == 'H'))
		printed += ux_print(fmt, ap);
	if (str_include("uxX", fmt->conv) && fmt->size == 'h')
		printed += uxh_print(fmt, ap);
	if (str_include("uxX", fmt->conv) && fmt->size == 'l')
		printed += uxl_print(fmt, ap);
	if (str_include("uxX", fmt->conv) && fmt->size == 'L')
		printed += uxll_print(fmt, ap);
	if (fmt->conv == 'p')
		printed += p_print(fmt, ap);
	if (fmt->conv == 'n' && !fmt->size)
		n_print(ap, printed);
	if (fmt->conv == 'n' && fmt->size == 'H')
		nhh_print(ap, printed);
	if (fmt->conv == 'n' && fmt->size == 'h')
		nh_print(ap, printed);
	if (fmt->conv == 'n' && fmt->size == 'L')
		nll_print(ap, printed);
	return (printed);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		printed;
	t_fmt	*fmt;

	va_start(ap, str);
	i = 0;
	printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			fmt = init_fmt();
			i += 1 + parse(str + i + 1, fmt, ap);
			printed = print_fmt(fmt, ap, printed);
			free(fmt);
			continue ;
		}
		write(1, &str[i], 1);
		i++;
		printed++;
	}
	va_end(ap);
	return (printed);
}
