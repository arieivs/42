/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:41:33 by svieira           #+#    #+#             */
/*   Updated: 2021/02/15 16:04:49 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	int		i;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count) //or count * size??
		((unsigned char *)res)[i++] = 0;
	return (res);
}
