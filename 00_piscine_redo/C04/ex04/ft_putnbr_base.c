/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:06:21 by svieira           #+#    #+#             */
/*   Updated: 2021/01/10 14:53:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnegnbr_base(int nbr, char *base, int base_size)
{
	if (nbr <= -base_size)
		ft_putnegnbr_base((nbr / base_size), base, base_size);
	ft_putchar(base[-(nbr % base_size)]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_size;

	base_size = ft_is_valid(base);
	if (base_size)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnegnbr_base(nbr, base, base_size);
		}
		else
			ft_putnegnbr_base(-nbr, base, base_size);
	}
}
