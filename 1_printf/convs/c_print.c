/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 12:01:05 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			c_print(t_fmt *fmt, va_list ap)
{
	unsigned char	c;
	int				extra_width;
	int				total_width;

	if (fmt->conv == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(ap, int);
	extra_width = 0;
	if (fmt->width > 1)
		extra_width = fmt->width - 1;
	total_width = extra_width + 1;
	if (!fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, &fmt->fill, 1);
	}
	write(1, &c, 1);
	if (fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, &fmt->fill, 1);
	}
	return (total_width);
}
