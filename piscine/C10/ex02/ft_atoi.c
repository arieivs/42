/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:26:33 by svieira           #+#    #+#             */
/*   Updated: 2021/01/29 14:53:55 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	is_signal(char c)
{
	return (c == '+' || c == '-');
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	// we don't need to handle + or - so it's all the same
	if (str[i] && is_signal(str[i]))
		i++;
	while (str[i] && is_number(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
