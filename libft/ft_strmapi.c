/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:10:02 by svieira           #+#    #+#             */
/*   Updated: 2021/02/17 12:52:50 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			strlen;
	char			*map_s;
	unsigned int	i;

	strlen = ft_strlen(s);
	map_s = (char *)malloc(sizeof(char) * strlen + 1);
	if (!map_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map_s[i] = f(i, s[i]);
		i++;
	}
	map_s[i] = 0;
	return (map_s);
}
