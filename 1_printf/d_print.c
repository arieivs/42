/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/03/31 17:00:10 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	d_zero_print(int n, char plus, int extra)
{
	if (plus && n >= 0)
		write(1, &plus, 1);
	if (n < 0)
		write(1, "-", 1);
	while (extra-- > 0)
		write(1, "0", 1);
	ft_putnbr_nosign(n);
}

static void	d_actual_print(int n, t_fmt *fmt, int extra_width, int extra_preci)
{
	if (fmt->fill == '0')
		d_zero_print(n, fmt->plus, extra_width);
	else
	{
		if (!fmt->left_align)
		{
			while (extra_width-- > 0)
				write(1, " ", 1);
		}
		d_zero_print(n, fmt->plus, extra_preci);
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
	int	extra_preci;
	int	extra_width;

	if (fmt->point && fmt->fill != ' ') // ignore 0 when precision exists
		fmt->fill = ' ';
	n = va_arg(ap, int);
	n_len = num_len(n, fmt->plus); // n_len includes -/+/space
	extra_preci = 0;
	if (n < 0 || fmt->plus) // force total precision to count with -/+/space
		fmt->precision++;
	if (fmt->precision > n_len)
		extra_preci = fmt->precision - n_len;
	extra_width = 0;
	if (fmt->width > n_len && fmt->width > fmt->precision)
	{
		if (fmt->precision > n_len)
			extra_width = fmt->width - fmt->precision;
		else
			extra_width = fmt->width - n_len; // width counts with -/+/space
	}
	printf("\nn len: %d extra width: %d extra preci: %d\n", n_len, extra_width, extra_preci);
	d_actual_print(n, fmt, extra_width, extra_preci);
	printf("returning %d", extra_preci + extra_width + n_len);
	return (extra_preci + extra_width + n_len);
}
