/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:43:16 by svieira           #+#    #+#             */
/*   Updated: 2021/01/11 21:21:28 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcomb(char *str, int sep)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (sep)
		write(1, ", ", 2);
}

char	*ft_init(char *comb, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		comb[i] = i + '0';
		i++;
	}
	comb[i] = '\0';
	return (comb);
}

char	*ft_refill(char *comb, int i)
{
	comb[i]++;
	i++;
	while (comb[i])
	{
		comb[i] = comb[i - 1] + 1;
		i++;
	}
	return (comb);
}

void	ft_print_combn(int n)
{
	int		i;
	char	comb[n];

	ft_init(comb, n);
	// while the first number doesnt reach its maximum value
	while (comb[0] < (10 - n + '0'))
	{
		i = n - 1;
		// increase the last number until 9 and print it
		while (comb[i] < '9')
		{
			ft_putcomb(comb, 1);
			comb[i]++;
		}
		ft_putcomb(comb, 1);
		// move backwards until the first number that didnt reach its max
		while (i >= 0 && comb[i] == (10 - n + i + '0'))
			i--;
		// reset comb (e.g. 189 -> 234) unless the first nb has reached its max
		if (i >= 0)
			ft_refill(comb, i);
	}
	ft_putcomb(comb, 0);
}
