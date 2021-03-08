/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:26:59 by svieira           #+#    #+#             */
/*   Updated: 2021/03/08 01:52:18 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnew_empty(void)
{
	char *str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

int			ft_memdel(void **ptr)
{
	if (!*ptr)
		return (0);
	ft_memset(*ptr, 0, ft_strlen(*ptr));
	free(*ptr);
	*ptr = NULL;
	return (1);
}

static int	gnl_core(int fd, char **line, char **cur_line, char *buf)
{
	int		rd;
	char	*temp;

	rd = 1;
	while (!ft_strchr(*cur_line, '\n') && (rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd] = 0;
		temp = ft_strjoin(*cur_line, buf);
		free(*cur_line);
		*cur_line = temp;
	}
	if (rd == -1)
		return (-1);
	if (rd == 0)
	{
		*line = ft_strdup(*cur_line);
		ft_memdel((void **)cur_line);
		return (0);
	}
	*line = ft_substr(*cur_line, 0, ft_strchr(*cur_line, '\n') - *cur_line);
	temp = ft_strdup(ft_strchr(*cur_line, '\n') + 1);
	free(*cur_line);
	*cur_line = temp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*cur_line = NULL;
	char		*buf;
	int			rd;

	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!cur_line)
	{
		if (!(cur_line = ft_strnew_empty()))
			return (-1);
	}
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	rd = gnl_core(fd, line, &cur_line, buf);
	free(buf);
	return (rd);
}
