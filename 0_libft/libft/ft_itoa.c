/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:10:45 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 12:24:00 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_strlen(int n)
{
	int	strlen;

	strlen = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		strlen++;
	while (n != 0)
	{
		strlen++;
		n /= 10;
	}
	return (strlen);
}

static char	*str_inv(char *str, int strlen)
{
	int		i;
	char	buff;

	i = 0;
	while (i < strlen / 2)
	{
		buff = str[i];
		str[i] = str[strlen - 1 - i];
		str[strlen - 1 - i] = buff;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		signal;
	int		i;

	str = (char *)malloc(sizeof(char) * find_strlen(n) + 1);
	if (!str)
		return (NULL);
	signal = -1;
	i = 0;
	if (n == 0)
		str[i++] = '0';
	if (n >= 0)
	{
		signal = 1;
		n *= -1;
	}
	while (n < 0)
	{
		str[i++] = -(n % 10) + '0';
		n /= 10;
	}
	if (signal < 0)
		str[i++] = '-';
	str[i] = 0;
	return (str_inv(str, i));
}
