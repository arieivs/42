/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diuxl_print_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:06:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 12:11:19 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putneglnbr(long int n)
{
	if (n <= -10)
		ft_putneglnbr(n / 10);
	ft_putchar_fd(-(n % 10) + '0', 1);
}

void	ft_put_lnbr_nosign(long int n)
{
	if (n < 0)
		ft_putneglnbr(n);
	else
		ft_putneglnbr(-n);
}

void	ft_put_ulnbr(unsigned long int n)
{
	if (n >= 10)
		ft_put_ulnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void	ft_put_xlnbr(unsigned long int n, char *base)
{
	if (n >= 16)
		ft_put_xlnbr(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}
