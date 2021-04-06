/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/06 17:42:10 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	uxl_num_len(unsigned long n, t_fmt *fmt)
{
	int	len;
	int	base;

	len = 0;
	base = 16;
	if (fmt->conv == 'u')
		base = 10;
	// don't count the number in special case
	// special case being when n is 0 and precision is explicitly 0
	if (n == 0 && !(fmt->point && fmt->precision == 0))
		len = 1;
	if (fmt->hash && fmt->conv != 'u' && n != 0)
		len += 2;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static void	uxl_zero_print(unsigned long n, t_fmt *fmt, int extra)
{
	if (fmt->hash && fmt->conv != 'u' && n != 0)
	{
		write(1, "0", 1);
		write(1, &fmt->conv, 1);
	}
	while (extra-- > 0)
		write(1, "0", 1);
	if (n == 0 && fmt->point && fmt->precision == 0)
		return ;
	if (fmt->conv == 'u')
		ft_put_ulnbr(n);
	else if (fmt->conv == 'x')
		ft_put_xlnbr(n, "0123456789abcdef");
	else
		ft_put_xlnbr(n, "0123456789ABCDEF");
}

static void	uxl_actual_print(unsigned long n, t_fmt *fmt, int xwidth, int xprec)
{
	if (fmt->fill == '0')
		uxl_zero_print(n, fmt, xwidth);
	else
	{
		if (!fmt->left_align)
		{
			while (xwidth-- > 0)
				write(1, " ", 1);
		}
		uxl_zero_print(n, fmt, xprec);
		if (fmt->left_align)
		{
			while (xwidth-- > 0)
				write(1, " ", 1);
		}
	}
}

int			uxl_print(t_fmt *fmt, va_list ap)
{
	unsigned long	n;
	int				n_len;
	int				real_preci;
	int				extra_preci;
	int				extra_width;

	n = (unsigned long)va_arg(ap, unsigned long);
	n_len = uxl_num_len(n, fmt); // n_len counts with 0x
	real_preci = fmt->precision;
	if (fmt->hash && fmt->conv != 'u' && n != 0) // force preci to count with 0x
		real_preci += 2;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ') // ignore 0 when precision exists
		fmt->fill = ' ';
	uxl_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
