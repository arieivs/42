/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:02:52 by svieira           #+#    #+#             */
/*   Updated: 2021/03/08 01:02:58 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;
	int		i;

	size = 0;
	while (s1[size])
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

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			s_len;
	char			*sub;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		sub = (char *)malloc(sizeof(char));
		sub[0] = 0;
		return (sub);
	}
	if (s_len - start < len)
		sub = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
