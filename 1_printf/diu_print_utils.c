/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:06:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/02 12:39:41 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			calc_width(int n_len, int width, int preci)
{
	int	extra_width;

	extra_width = 0;
	if (width > n_len && width > preci)
	{
		if (preci > n_len)
			extra_width = width - preci;
		else
			extra_width = width - n_len; // width counts with -/+/space
	}
	return (extra_width);
}

static void	ft_putnegnbr(int n)
{
	if (n <= -10)
		ft_putnegnbr(n / 10);
	ft_putchar_fd(-(n % 10) + '0', 1);
}

void		ft_putnbr_nosign(int n)
{
	if (n < 0)
		ft_putnegnbr(n);
	else
		ft_putnegnbr(-n);
}

void		ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}
