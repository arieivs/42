/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/02 12:31:50 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	unum_len(unsigned int n, char plus)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (plus)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	u_zero_print(unsigned int n, t_fmt *fmt, int extra)
{
	if (fmt->plus && n >= 0)
		write(1, &fmt->plus, 1);
	while (extra-- > 0)
		write(1, "0", 1);
	if (n != 0 || !fmt->point || fmt->precision != 0)
		ft_putunbr(n);
}

static void	u_actual_print(unsigned int n, t_fmt *fmt, int xwidth, int xpreci)
{
	if (fmt->fill == '0')
		u_zero_print(n, fmt, xwidth);
	else
	{
		// putting the space on the right side of the + in the special case
		// special case being n = 0 with explicit 0 precision
		// if there's no width, we want to keep it that way
		if (n == 0 && fmt->point && fmt->precision == 0 && fmt->width != 0)
			xwidth++;
		if (!fmt->left_align)
		{
			while (xwidth-- > 0)
				write(1, " ", 1);
		}
		u_zero_print(n, fmt, xpreci);
		if (fmt->left_align)
		{
			while (xwidth-- > 0)
				write(1, " ", 1);
		}
	}
}

int			u_print(t_fmt *fmt, va_list ap)
{
	unsigned int	n;
	int				n_len;
	int				real_preci;
	int				extra_preci;
	int				extra_width;

	n = va_arg(ap, unsigned int);
	n_len = unum_len(n, fmt->plus); // n_len includes +/space
	// if there's no width and we have special case, we return 0
	if (n == 0 && fmt->point && fmt->precision == 0 && fmt->width == 0)
		n_len = 0;
	real_preci = fmt->precision;
	if (fmt->plus) // force total precision to count with +/space
		real_preci++;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ') // ignore 0 when precision exists
		fmt->fill = ' ';
	u_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
