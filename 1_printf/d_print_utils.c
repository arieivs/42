/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:06:40 by svieira           #+#    #+#             */
/*   Updated: 2021/03/31 16:08:44 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			num_len(int n, char plus)
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
