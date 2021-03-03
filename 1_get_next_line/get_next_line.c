/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:13:52 by svieira           #+#    #+#             */
/*   Updated: 2021/03/03 18:12:49 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*curr_line = NULL;
	char		*next_line;
	int			read_size;
	char		buff[BUFFER_SIZE + 1];

	if (curr_line = NULL)
		curr_line = (char *)malloc(sizeof(char));
	next_line = ft_strchr(curr_line, '\n');
	if (next_line)
		// *line = curr_line until \n
		// currline = nex_tline
		// return (1) ?
	// *line = curr_line
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0 && !ft_strchr(buff, '\n'))
	{
		buff[read_size] = 0;
		// join buff to end of *line
	}
	read_size = read(fd, buff, BUFFER_SIZE);
	// join buff until \n to end of *line
	// curr_line = resto do buff (dps do \n)
	//return 0 or 1 accordinggly
}
