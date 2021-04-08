/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/08 23:44:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	f_actual_print(double f, t_fmt *fmt, int extra_width)
{
	if (!fmt->left_align && fmt->fill == ' ')
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
	if (fmt->plus && (f > 0 || 1 / f == INFINITY))
		write(1, &fmt->plus, 1);
	if (f < 0 || 1 / f == -INFINITY)
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
