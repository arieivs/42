/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:13:52 by svieira           #+#    #+#             */
/*   Updated: 2021/02/24 13:05:13 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buff;
	int		read_size;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_size = read(fd, buff, BUFFER_SIZE);
	buff[read_size] = 0;
	if (read_size < 0)
		return (-1);
	if (BUFFER_SIZE >= read_size)
		return (0)
	return (1);
}
