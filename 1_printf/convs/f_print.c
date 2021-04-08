/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/08 22:26:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

static long int	ft_tail_rec_power(int nb, int power, long int acc)
{
	if (power == 0)
		return (acc);
	return (ft_tail_rec_power(nb, power - 1, (long int)nb * acc));
}

long int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_tail_rec_power(nb, power, 1));
}

static int	lnum_len(long int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	fnum_len(double f, t_fmt *fmt)
{
	int			len;
	long int	bef;
	long int	aft;
	long int	next;

	len = 0;
	if (f < 0 || 1 / f == -INFINITY || fmt->plus)
		len++;
	if (f > 0)
		f *= -1;
	bef = (long int)f;
	aft = (f - bef) * ft_recursive_power(10, fmt->precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, fmt->precision + 1);
	// rounding needs extra digit, 1st e.g: 9.5 -> 10, 2nd e.g: 9.99 -> 10.0
	if (next >= 5 && (bef % 10) == -9 &&
		(!fmt->precision || lnum_len(aft - 1) > fmt->precision))
		len++;
	if (bef == 0)
		len++;
	while (bef != 0)
	{
		len++;
		bef = bef / 10;
	}
	if (fmt->precision || fmt->hash) //counting with the .
		len++;
	return (len + fmt->precision);
}

void	ft_putfloat_nosign(double f, int precision, int hash)
{
	long int	bef;
	long int	aft;
	double		nextn;
	int			extra_zeros;

	if (f > 0)
		f *= -1;
	bef = (long int)f;
	aft = (f - bef) * ft_recursive_power(10, precision);
	nextn = (aft * 100) - (f - bef) * ft_recursive_power(10, precision + 2);
	// rounding to units, 4.5 -> 4 but 4.51 -> 5 and 5.5 -> 6
	if (!precision && (nextn > 50 || (nextn >= 50 && bef % 2 != 0)))
		bef--;
	else if (precision && nextn >= 50)
	{
		// rouding if aft is all 9s 3.999 -> 4.00
		if (lnum_len(aft - 1) > precision)
		{
			bef--;
			aft = 0;
		}
		else
			aft--;
	}
	ft_put_lnbr_nosign(bef);
	if (precision || hash)
		write(1, ".", 1);
	if (precision)
	{
		extra_zeros = precision - lnum_len(aft);
		while (extra_zeros-- > 0)
			write(1, "0", 1);
		ft_put_lnbr_nosign(aft);
	}
}

static void	f_actual_print(double f, t_fmt *fmt, int extra_width)
{
	if (!fmt->left_align && fmt->fill == ' ')
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
	if (fmt->plus && (f > 0 || 1 / f == INFINITY))
		write(1, &fmt->plus, 1);
	if (f < 0 || 1 / f == -INFINITY )
		write(1, "-", 1);
	if (fmt->fill == '0')
	{
		while (extra_width-- > 0)
			write(1, "0", 1);
	}
	if (f == INFINITY || f == -INFINITY)
		write(1, "inf", 3);
	else if (f != f)
		write(1, "nan", 3);
	else
		ft_putfloat_nosign(f, fmt->precision, fmt->hash);
	if (fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
}

int	f_print(t_fmt *fmt, va_list ap)
{
	double	f;
	int		f_len;
	int		extra_width;

	f = va_arg(ap, double); // float is promoted to double, thus undefined behv
	if (!fmt->point)
		fmt->precision = 6;
	if (f == INFINITY || f == -INFINITY || f != f)
	{
		f_len = 3;
		if (f == -INFINITY || fmt->plus)
			f_len = 4;
		fmt->fill = ' '; // 0 flag is ignored in these cases
	}
	else
		f_len = fnum_len(f, fmt); // f_len includes -/+/space, . and precision
	extra_width = 0;
	if (fmt->width > f_len)
		extra_width = fmt->width - f_len;
	f_actual_print(f, fmt, extra_width);
	return (extra_width + f_len);
}
