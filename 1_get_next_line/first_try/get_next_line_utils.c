/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:24 by svieira           #+#    #+#             */
/*   Updated: 2021/03/06 17:33:42 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew_empty(void)
{
	char *str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlen_chr(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	*ft_strdup_chr(const char *s1, char c)
{
	int		size;
	char	*s2;
	int		i;

	if (!s1)
	{
		s2 = (char *)malloc(sizeof(char));
		s2[0] = 0;
		return (s2);
	}
	size = 0;
	while (s1[size] && s1[size] != c)
		size++;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[size] = 0;
	return (s2);
}

char	*ft_strjoin_chr(char *s1, char *s2, char c)
{
	int		size1;
	char	*s3;
	int		i;

	size1 = ft_strlen_chr(s1, 0);
	s3 = (char *)malloc(sizeof(char) * (size1 + ft_strlen_chr(s2, c) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] && s2[i] != c)
	{
		s3[size1 + i] = s2[i];
		i++;
	}
	s3[size1 + i] = 0;
	free(s1);
	return (s3);
}
