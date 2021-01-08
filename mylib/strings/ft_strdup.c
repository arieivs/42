/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:55:17 by svieira           #+#    #+#             */
/*   Updated: 2020/12/12 20:05:47 by svieira          ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		i;
	int		srclen;
	char	*cpy;

	i = 0;
	srclen = ft_strlen(src);
	if (srclen == 0)
	{
		cpy = malloc(sizeof(char));
		cpy[0] = '\0';
		return (cpy);
	}
	cpy = malloc(sizeof(*src) * (srclen + 1));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
