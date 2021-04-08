/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:43:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/08 23:44:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	fnum_len(double f, t_fmt *fmt)
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
	// mixing two separate things in same if because of nbr lines issue
	// rounding needs extra digit, 1st e.g: 9.5 -> 10, 2nd e.g: 9.99 -> 10.0
	if (bef == 0 || (next >= 5 && (bef % 10) == -9 &&
		(!fmt->precision || lnum_len(aft - 1) > fmt->precision)))
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

static void	ft_actual_putfloat(long int bef, long int aft, int prec, int hash)
{
	int	extra_zeros;

	ft_put_lnbr_nosign(bef);
	if (prec || hash)
		write(1, ".", 1);
	if (prec)
	{
		extra_zeros = prec - lnum_len(aft);
		while (extra_zeros-- > 0)
			write(1, "0", 1);
		ft_put_lnbr_nosign(aft);
	}
}

void	ft_putfloat_nosign(double f, int precision, int hash)
{
	long int	bef;
	long int	aft;
	double		nextn;

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
	ft_actual_putfloat(bef, aft, precision, hash);
}
