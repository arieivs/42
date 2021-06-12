/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:37:32 by svieira           #+#    #+#             */
/*   Updated: 2021/01/18 16:14:42 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_non_printable(char c)
{
	return (c <= 31 || c >= 127);
}

void	ft_puthexa(unsigned int dec)
{
	char hexa1;
	char hexa2;

	hexa1 = "0123456789abcdef"[dec / 16];
	hexa2 = "0123456789abcdef"[dec % 16];
	write(1, "\\", 1);
	write(1, &hexa1, 1);
	write(1, &hexa2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	dec;

	while (*str)
	{
		if (is_non_printable(*str))
		{
			dec = *str;
			if (dec < 0)
				dec += 256;
			ft_puthexa(dec);
		}
		else
			write(1, str, 1);
		str++;
	}
}
