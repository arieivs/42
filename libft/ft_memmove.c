/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:49:31 by svieira           #+#    #+#             */
/*   Updated: 2021/02/11 14:24:41 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src + i == dst)
		{
			i = len - 1;
			while (i > 0)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i--;
			}
			((unsigned char *)dst)[0] = ((unsigned char *)src)[0];
			return (dst);
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
