/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:08:11 by svieira           #+#    #+#             */
/*   Updated: 2020/12/13 11:22:19 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	i = 0;
	str_len = 0;
	while (i < size)
		str_len += ft_strlen(strs[i++]);
	str_len += (ft_strlen(sep) * (size - 1));
	str = (char*)malloc(sizeof(char) * (str_len + 1));
	str[0] = '\0';
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(str, strs[i++]);
		ft_strcat(str, sep);
	}
	ft_strcat(str, strs[i]);
	return (str);
}
