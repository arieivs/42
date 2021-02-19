/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:52:49 by svieira           #+#    #+#             */
/*   Updated: 2021/02/19 12:05:24 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size1;
	int		size2;
	char	*s3;
	int		i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[size1 + i] = s2[i];
		i++;
	}
	s3[size1 + i] = 0;
	return (s3);
}
