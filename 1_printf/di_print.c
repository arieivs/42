/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/02 11:58:40 by svieira          ###   ########.fr       */
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

static void	d_zero_print(int n, t_fmt *fmt, int extra)
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

static void	d_actual_print(int n, t_fmt *fmt, int extra_width, int extra_preci)
{
	if (fmt->fill == '0')
		d_zero_print(n, fmt, extra_width);
	else
	{
		// putting the space on the right side of the + in the special case
		// special case being n = 0 with explicit 0 precision
		// if there's no width, we want to keep it that way
		if (n == 0 && fmt->point && fmt->precision == 0 && fmt->width != 0)
			extra_width++;
		if (!fmt->left_align)
		{
			while (extra_width-- > 0)
				write(1, " ", 1);
		}
		d_zero_print(n, fmt, extra_preci);
		if (fmt->left_align)
		{
			while (extra_width-- > 0)
				write(1, " ", 1);
		}
	}
}

int			d_print(t_fmt *fmt, va_list ap)
{
	int	n;
	int	n_len;
	int	real_preci;
	int	extra_preci;
	int	extra_width;

	n = va_arg(ap, int);
	n_len = num_len(n, fmt->plus); // n_len includes -/+/space
	// if there's no width and we have special case, we return 0
	if (n == 0 && fmt->point && fmt->precision == 0 && fmt->width == 0)
		n_len = 0;
	real_preci = fmt->precision;
	if (n < 0 || fmt->plus) // force total precision to count with -/+/space
		real_preci++;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ') // ignore 0 when precision exists
		fmt->fill = ' ';
	d_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
