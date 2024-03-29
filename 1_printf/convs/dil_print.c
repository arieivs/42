/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dil_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/09 10:50:19 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	l_num_len(long int n, t_fmt *fmt)
{
	int	len;

	len = 0;
	if (n == 0 && !(fmt->point && fmt->precision == 0))
		len = 1;
	if (n < 0 || fmt->plus)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	dil_zero_print(long int n, t_fmt *fmt, int extra)
{
	if (fmt->plus && n >= 0)
		write(1, &fmt->plus, 1);
	if (n < 0)
		write(1, "-", 1);
	while (extra-- > 0)
		write(1, "0", 1);
	if (n != 0 || !fmt->point || fmt->precision != 0)
		ft_put_lnbr_nosign(n);
}

static void	dil_actual_print(long int n, t_fmt *fmt, int xwd, int xprec)
{
	if (fmt->fill == '0')
		dil_zero_print(n, fmt, xwd);
	else
	{
		if (!fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
		dil_zero_print(n, fmt, xprec);
		if (fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
	}
}

int	dil_print(t_fmt *fmt, va_list ap)
{
	long int	n;
	int			n_len;
	int			real_preci;
	int			extra_preci;
	int			extra_width;

	n = va_arg(ap, long int);
	n_len = l_num_len(n, fmt);
	real_preci = fmt->precision;
	if (n < 0 || (fmt->plus && !(n == 0 && fmt->point && fmt->precision == 0)))
		real_preci++;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ')
		fmt->fill = ' ';
	dil_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
