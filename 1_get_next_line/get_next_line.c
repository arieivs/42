/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:13:52 by svieira           #+#    #+#             */
/*   Updated: 2021/03/05 23:59:43 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		use_curr_line(char **line, char **curr_line)
{
	*line = ft_strdup_chr(*curr_line, '\n');
	if (!*line)
		return (-1);
	*curr_line = ft_strdup_chr(ft_strchr(*curr_line, '\n'), 0);
	if (!*curr_line)
		return (-1);
	return (1);
}

int		read_file(int fd, char **line, char **curr_line)
{
	char	*buff;
	int		rd;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	*line = *curr_line;
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = 0;
		*line = ft_strjoin_chr(*line, buff, '\n');
		if (!*line)
			return (-1);
		if (ft_strchr(buff, '\n'))
		{
			*curr_line = ft_strdup_chr(ft_strchr(buff, '\n'), 0);
			if (!*curr_line)
				return (-1);
			break ;
		}
	}
	free(buff);
	if (rd <= 0)
		return (rd);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*curr_line = NULL;
	int	rd;

	if (fd < 0)
		return (-1);
	if (!curr_line)
	{
		if (!(curr_line = ft_strnew_empty()))
			return (-1);
	}
	if (ft_strchr(curr_line, '\n'))
		return (use_curr_line(line, &curr_line));
	rd = read_file(fd, line, &curr_line);
	//if (rd == 0 && curr_line[0])
	//	return (use_curr_line(line, &curr_line));
	return (rd);
}
