/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:04:19 by svieira           #+#    #+#             */
/*   Updated: 2021/01/20 11:13:07 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(int size, char **strs, char *sep)
{
	int i;
	int j;
	int strlen;

	i = 0;
	strlen = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		strlen += j;
		i++;
	}
	j = 0;
	while (sep[j])
		j++;
	strlen += j * (size - 1);
	return (strlen);
}

char	*ft_strcpy(int *j, char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[*j] = src[i];
		*j += 1;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		strlen;
	char	*str;
	int		i;
	int		j;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(str));
		str[0] = 0;
		return (str);
	}
	strlen = ft_strlen(size, strs, sep);
	str = (char *)malloc(sizeof(str) * (strlen + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		ft_strcpy(&j, str, strs[i++]);
		ft_strcpy(&j, str, sep);
	}
	ft_strcpy(&j, str, strs[i]);
	str[strlen] = 0;
	return (str);
}
