/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:02:13 by svieira           #+#    #+#             */
/*   Updated: 2021/06/01 15:05:12 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Differences from project GNL:
 * fd = 0
 * no fd changes between function calls
 * no buffer size variable
 * buffer_size = 1 makes our lives easier
 */

int	get_next_line(char **line)
{
	char	*cur_line;
	char	*buff;
	char	*tmp;
	int		rd;

	if (!line)
		return (-1);
	cur_line = (char *)malloc(sizeof(char));
	cur_line[0] = 0;
	buff = (char *)malloc(sizeof(char) * 2);
	while ((rd = read(0, buff, 1)) > 0 && buff[0] != '\n')
	{
		buff[1] = 0;
		tmp = concat(cur_line, buff);
		free(cur_line);
		cur_line = tmp;
		// or I free cur_line inside concat
	}


