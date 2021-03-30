/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/03/30 19:58:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	num_len(int n, char plus)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0 || plus)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int			d_print(t_fmt *fmt, va_list ap)
{
	int	n;
	int	n_len;
	int	extra_preci;
	int	extra_width;

	n = va_arg(ap, int);
	n_len = num_len(n, fmt->plus);
	extra_preci = 0;
	if (fmt->precision > n_len)
		extra_preci = fmt->precision - n_len;
	extra_width = 0;
	if (fmt->width > n_len)
		extra_width = fmt->width - n_len;
	printf("\nn len: %d extra width: %d\n", n_len, extra_width);
	//if (fmt->plus && n >= 0)
		// colocar o fill
	return (0);
}
