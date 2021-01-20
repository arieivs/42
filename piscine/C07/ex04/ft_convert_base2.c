/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:48:53 by svieira           #+#    #+#             */
/*   Updated: 2021/01/20 20:34:11 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		ft_is_space(char c);
int		ft_atoi_base(char *nbr, char *base_from);

int		ft_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
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
	return (1);
}

char	*ft_rev_str(char *str, int str_len)
{
	int		i;
	char	buff;

	i = 0;
	while (i < str_len / 2)
	{
		buff = str[i];
		str[i] = str[str_len - 1 - i];
		str[str_len - 1 - i] = buff;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int nb, char *base_to)
{
	int		i;
	int		base_len;
	char	*str;
	int		signal;

	i = 0;
	base_len = ft_strlen(base_to);
	str = (char *)malloc(sizeof(str) * 34);
	signal = nb >= 0 ? 1 : -1;
	if (nb > 0)
		nb *= -1;
	while (nb < 0)
	{
		str[i] = base_to[-nb % base_len];
		nb /= base_len;
		i++;
	}
	if (signal < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = 0;
	printf("before rev: %s\n", str);
	ft_rev_str(str, i);
	printf("after rev: %s\n", str);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;

	if (!ft_is_valid(base_from) || !ft_is_valid(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(nb, base_to);
	return (str);
}
