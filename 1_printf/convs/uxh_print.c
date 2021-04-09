/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxh_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/09 10:57:21 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	short_ux_num_len(unsigned short int n, t_fmt *fmt)
{
	int	len;
	int	base;

	len = 0;
	base = 16;
	if (fmt->conv == 'u')
		base = 10;
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

static void	uxh_zero_print(unsigned short int n, t_fmt *fmt, int extra)
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
		ft_put_unbr(n);
	else if (fmt->conv == 'x')
		ft_put_xnbr(n, "0123456789abcdef");
	else
		ft_put_xnbr(n, "0123456789ABCDEF");
}

static void	uxh_actual_print(unsigned short int n, t_fmt *fmt, int xwd, int xpr)
{
	if (fmt->fill == '0')
		uxh_zero_print(n, fmt, xwd);
	else
	{
		if (!fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
		uxh_zero_print(n, fmt, xpr);
		if (fmt->left_align)
		{
			while (xwd-- > 0)
				write(1, " ", 1);
		}
	}
}

int	uxh_print(t_fmt *fmt, va_list ap)
{
	unsigned short int	n;
	int					n_len;
	int					real_preci;
	int					extra_preci;
	int					extra_width;

	n = (unsigned short int)va_arg(ap, unsigned int);
	n_len = short_ux_num_len(n, fmt);
	real_preci = fmt->precision;
	if (fmt->hash && fmt->conv != 'u' && n != 0)
		real_preci += 2;
	extra_preci = 0;
	if (real_preci > n_len)
		extra_preci = real_preci - n_len;
	extra_width = calc_width(n_len, fmt->width, real_preci);
	if (fmt->point && fmt->fill != ' ')
		fmt->fill = ' ';
	uxh_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
