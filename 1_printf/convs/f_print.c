/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 23:15:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_tail_rec_power(int nb, int power, int acc)
{
	if (power == 0)
		return (acc);
	return (ft_tail_rec_power(nb, power - 1, nb * acc));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (ft_tail_rec_power(nb, power, 1));
}

static int	fnum_len(double f, t_fmt *fmt)
{
	int	len;
	int	bef;
	int	aft;
	int	next;

	len = 0;
	if (f == 0)
		len = 1;
	if (f < 0 || fmt->plus)
		len++;
	if (f > 0)
		f *= -1;
	bef = (int)f;
	aft = (f - bef) * ft_recursive_power(10, fmt->precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, fmt->precision + 1);
	while (bef != 0)
	{
		len++;
		bef = bef / 10;
	}
	if (!fmt->precision && next >= 5) //rounding demands an extra digit
		len++;
	if (fmt->precision) //counting with the .
		len++;
	return (len + fmt->precision);
}

void	ft_putfloat_nosign(double f, int precision)
{
	int	bef;
	int	aft;
	int	next;

	if (f > 0)
		f *= -1;
	bef = (int)f;
	aft = (f - bef) * ft_recursive_power(10, precision);
	next = (aft * 10) - (f - bef) * ft_recursive_power(10, precision + 1);
	if (!precision && next >= 5)
		bef--;
	else if (next >= 5)
		aft--;
	ft_putnbr_nosign(bef);
	if (precision)
	{
		write(1, ".", 1);
		ft_putnbr_nosign(aft);
	}
}

static void	f_actual_print(double f, t_fmt *fmt, int extra_width)
{
	if (!fmt->left_align && fmt->fill == ' ')
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
	if (fmt->plus && f >= 0)
		write(1, &fmt->plus, 1);
	if (f < 0)
		write(1, "-", 1);
	if (fmt->fill == '0')
	{
		while (extra_width-- > 0)
			write(1, "0", 1);
	}
	ft_putfloat_nosign(f, fmt->precision);
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
	f_len = fnum_len(f, fmt); // f_len includes -/+/space, . and precision
	extra_width = 0;
	if (fmt->width > f_len)
		extra_width = fmt->width - f_len;
	f_actual_print(f, fmt, extra_width);
	return (extra_width + f_len);
}
