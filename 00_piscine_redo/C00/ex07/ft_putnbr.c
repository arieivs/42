/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:35:15 by svieira           #+#    #+#             */
/*   Updated: 2021/01/09 11:01:42 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnegnbr(int nb)
{
	if (nb <= -10)
		ft_putnegnbr(nb / 10);
	ft_putchar(-(nb % 10) + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnegnbr(nb);
	}
	else
		ft_putnegnbr(-nb);
}
