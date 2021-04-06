/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diuxll_print_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:06:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/06 14:41:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnegllnbr(long long int n)
{
	if (n <= -10)
		ft_putnegllnbr(n / 10);
	ft_putchar_fd(-(n % 10) + '0', 1);
}

void		ft_put_llnbr_nosign(long long int n)
{
	if (n < 0)
		ft_putnegllnbr(n);
	else
		ft_putnegllnbr(-n);
}

void		ft_put_ullnbr(unsigned long long int n)
{
	if (n >= 10)
		ft_put_ullnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void		ft_put_xllnbr(unsigned long long int n, char *base)
{
	if (n >= 16)
		ft_put_xllnbr(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}
