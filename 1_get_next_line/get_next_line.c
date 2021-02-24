/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:13:52 by svieira           #+#    #+#             */
/*   Updated: 2021/02/24 20:11:58 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		read_size;

	read_size = read(fd, *line, BUFFER_SIZE);
	*line[read_size] = 0;
	// assim recebo a mais:
	if (read_size <= 0)
		return (read_size);
	// assim recebo a menos:
	/*if (BUFFER_SIZE > read_size)
		return (0);*/
	return (1);
}
