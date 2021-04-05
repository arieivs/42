/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/05 11:34:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ux_num_len(unsigned int n, char conv, int hash)
{
	int	len;
	int	base;

	len = 0;
	base = 16;
	if (conv == 'u')
		base = 10;
	if (n == 0)
		len = 1;
	if (hash && conv != 'u' && n != 0)
		len += 2;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

static void	ux_zero_print(unsigned int n, t_fmt *fmt, int extra)
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

static void	ux_actual_print(unsigned int n, t_fmt *fmt, int xwidth, int xpreci)
{
	if (fmt->fill == '0')
		ux_zero_print(n, fmt, xwidth);
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
		ux_zero_print(n, fmt, xpreci);
		if (fmt->left_align)
		{
			while (xwidth-- > 0)
				write(1, " ", 1);
		}
	}
}

int			ux_print(t_fmt *fmt, va_list ap)
{
	unsigned int	n;
	int				n_len;
	int				extra_preci;
	int				extra_width;

	n = va_arg(ap, unsigned int);
	n_len = ux_num_len(n, fmt->conv, fmt->hash); // n_len counts with 0x
	// if there's no width and we have special case, we n_len is 0
	if (n == 0 && fmt->point && fmt->precision == 0 && fmt->width == 0)
		n_len = 0;
	extra_preci = 0;
	if (fmt->precision > n_len)
		extra_preci = fmt->precision - n_len;
	extra_width = calc_width(n_len, fmt->width, fmt->precision);
	if (fmt->point && fmt->fill != ' ') // ignore 0 when precision exists
		fmt->fill = ' ';
	ux_actual_print(n, fmt, extra_width, extra_preci);
	return (extra_preci + extra_width + n_len);
}
