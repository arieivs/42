/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:47:10 by svieira           #+#    #+#             */
/*   Updated: 2021/02/02 18:47:45 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		get_size(char *path, int buff_size)
{
	int		fd;
	int		file_size;
	int		read_size;
	char	buff[buff_size];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		put_strerr(strerror(errno));
		return (-1);
	}
	file_size = 0;
	while ((read_size = read(fd, buff, buff_size)) != 0)
	{
		buff[read_size] = 0;
		file_size += read_size;
	}
	if (close(fd) == -1)
	{
		put_strerr(strerror(errno));
		return (-1);
	}
	return (file_size);
}

void	rd_stdin_wr(int fd_dest, int buff_size)
{
	int		read_size;
	char	buff[buff_size + 1];

	while ((read_size = read(0, buff, buff_size)) != 0)
		buff[read_size] = 0;
	write(fd_dest, 0, 1);
}

void	o_rd_wr_c(char *path_src, int fd_dest, int head_size, int tail_size)
{
	int		fd_src;
	int		read_size;
	char	head[head_size + 1];
	char	tail[tail_size + 1];

	fd_src = open(path_src, O_RDONLY);
	if (fd_src == -1)
	{
		put_strerr(strerror(errno));
		return ;
	}
	if ((read_size = read(fd_src, head, head_size)) != 0)
		head[read_size] = 0;
	if ((read_size = read(fd_src, tail, tail_size)) != 0)
	{
		tail[read_size] = 0;
		write(fd_dest, tail, read_size);
	}
	if (close(fd_src) == -1)
		put_strerr(strerror(errno));
}
