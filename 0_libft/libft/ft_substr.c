/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:42:22 by svieira           #+#    #+#             */
/*   Updated: 2021/02/19 11:47:59 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
