/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:02:13 by svieira           #+#    #+#             */
/*   Updated: 2021/11/03 23:35:49 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* prototype: char	*get_next_line(int fd);
 * return a line that has been read from fd
 * the line should be returned including the '\n' if it exists
 * if the buffer is empty, return NULL
 * in case of error, return NULL
 * compile with the flag -D BUFFER_SIZE=xx
 * no need to handle reading from different files
 */

char	*get_next_line(int fd)
{
	/*char	*cur_line;
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
	}*/
}

