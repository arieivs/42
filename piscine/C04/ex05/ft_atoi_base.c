/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:01 by svieira           #+#    #+#             */
/*   Updated: 2021/01/10 17:10:42 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_is_signal(char c)
{
	return (c == '-' || c == '+');
}

int	ft_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (ft_is_signal(base[i]) || ft_is_space(base[i]))
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

int	ft_is_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_size;
	int i;
	int signal;
	int nb;
	int i_base;

	if (!(base_size = ft_is_valid(base)))
		return (0);
	i = 0;
	signal = 1;
	nb = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && ft_is_signal(str[i]))
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] && (i_base = ft_is_base(str[i], base)))
	{
		nb = nb * base_size + (i_base - 1);
		i++;
	}
	return (nb * signal);
}
