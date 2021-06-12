/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:35:53 by svieira           #+#    #+#             */
/*   Updated: 2021/01/15 11:54:52 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_comb(int left, int right)
{
	ft_putchar(left / 10 + '0');
	ft_putchar(left % 10 + '0');
	write(1, " ", 1);
	ft_putchar(right / 10 + '0');
	ft_putchar(right % 10 + '0');
	if (left != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	right = 1;
	while (left < 99 && left < right)
	{
		right = left + 1;
		while (right <= 99)
		{
			ft_put_comb(left, right);
			right++;
		}
		left++;
	}
}
