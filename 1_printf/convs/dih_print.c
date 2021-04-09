/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dih_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/09 10:49:34 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	short_num_len(short int n, t_fmt *fmt)
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

static void	dih_zero_print(short int n, t_fmt *fmt, int extra)
{
	if (fmt->plus && n >= 0)
		write(1, &fmt->plus, 1);
	if (n < 0)
		write(1, "-", 1);
	while (extra-- > 0)
		write(1, "0", 1);
	if (n != 0 || !fmt->point || fmt->precision != 0)
		ft_putnbr_nosign(n);
}

static void	dih_actual_print(short int n, t_fmt *fmt, int x_width, int x_preci)
{
	if (fmt->fill == '0')
		dih_zero_print(n, fmt, x_width);
	else
	{
		if (!fmt->left_align)
		{
			while (x_width-- > 0)
				write(1, " ", 1);
		}
		dih_zero_print(n, fmt, x_preci);
		if (fmt->left_align)
		{
			while (x_width-- > 0)
				write(1, " ", 1);
		}
	}
}

int	dih_print(t_fmt *fmt, va_list ap)
{
	short int	n;
	int			n_len;
	int			real_preci;
	int			extra_preci;
	int			extra_width;

	n = (short int)va_arg(ap, int);
	n_len = short_num_len(n, fmt);
	real_preci = fmt->precision;
	if (n < 0 || (fmt->plus && !(n == 0 && fmt->point && fmt->precision == 0)))
		real_preci++;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ')
		fmt->fill = ' ';
	dih_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
