/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:26:59 by svieira           #+#    #+#             */
/*   Updated: 2021/03/08 23:53:18 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_line		*ft_linenew(int fd)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->fd = fd;
	line->str = (char *)malloc(sizeof(char));
	if (!line->str)
		return (NULL);
	line->str[0] = 0;
	line->next = 0;
	return (line);
}

t_line		*ft_linefind(t_line *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void		ft_linedel(t_line **list, int fd)
{
	t_line	*cur_line;
	t_line	*to_delete;

	cur_line = *list;
	if (cur_line->fd == fd)
	{
		*list = cur_line->next;
		free(cur_line->str);
		free(cur_line);
		cur_line = NULL;
		return ;
	}
	while (cur_line->next)
	{
		if (cur_line->next->fd == fd)
		{
			to_delete = cur_line->next;
			cur_line->next = to_delete->next;
			free(to_delete->str);
			free(to_delete);
			to_delete = NULL;
			return ;
		}
		cur_line = cur_line->next;
	}
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
	static t_line	*cur_line = NULL;
	t_line			*to_use;
	char			*buf;
	int				rd;

	if (read(fd, 0, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!cur_line)
	{
		if (!(cur_line = ft_linenew(fd)))
			return (-1);
	}
	if (!(to_use = ft_linefind(cur_line, fd)))
	{
		to_use = ft_linenew(fd);
		to_use->next = cur_line;
		cur_line = to_use;
	}
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	rd = gnl_core(fd, line, &(to_use->str), buf);
	if (rd == 0)
		ft_linedel(&cur_line, fd);
	free(buf);
	return (rd);
}
