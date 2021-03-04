/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:13:52 by svieira           #+#    #+#             */
/*   Updated: 2021/03/04 21:47:59 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew_empty(void)
{
	char *str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

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

int		get_next_line(int fd, char **line)
{
	static char	*curr_line = NULL;
	int			rd;
	char		buff[BUFFER_SIZE + 1];

	if (!curr_line)
	{
		if (!(curr_line = ft_strnew_empty()))
			return (-1);
	}
	if (ft_strchr(curr_line, '\n'))
		return (use_curr_line(line, &curr_line));
	*line = curr_line;
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = 0;
		if (!(*line = ft_strjoin_chr(*line, buff, '\n')))
			return (-1);
		if (ft_strchr(buff, '\n'))
		{
			if (!(curr_line = ft_strdup_chr(ft_strchr(buff, '\n'), 0)))
				return (-1);
			break ;
		}
	}
	return (rd > 0 ? 1 : rd);
}
