/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:48 by svieira           #+#    #+#             */
/*   Updated: 2021/02/23 12:27:02 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i + j < dstsize - 1 && dstsize != 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize != 0 || dstsize < i)
		dst[i + j] = 0;
	while (src[j])
		j++;
	if (dstsize < i)
		return (dstsize + j);
	return (i + j);
}
