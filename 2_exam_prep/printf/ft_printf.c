/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:42:38 by svieira           #+#    #+#             */
/*   Updated: 2021/11/05 01:16:49 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
 * prototype: int ft_printf(const char *, ... );
 * allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
 * manage conversions s, d and x
 */

static void	put_str(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		 size++;
	write(1, str, size);
}

static void put_nbr_neg(int nb, int base, char *base_set)
{
	char c;

	if (nb == 0)
		return ;
	put_nbr_neg(nb / base, base, base_set);
	c = base_set[(nb % base) * -1];
	write(1, &c, 1);
}

static void	put_nbr(int nb, int base, char *base_set)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
		write(1, "-", 1);
	if (nb > 0)
		nb *= -1; 
	put_nbr_neg(nb, base, base_set);
}

int	main(void)
{
	put_nbr(120, 16, "0123456789abcdef");
	put_str("\nhello!\n");
	put_nbr(0, 10, "0123456789");
	put_str("\nagain\n");
	put_nbr(-1678, 10, "0123456789");
	put_str("\nlast\n");
	return (0);
}
