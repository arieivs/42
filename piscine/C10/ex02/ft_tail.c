/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:42:58 by svieira           #+#    #+#             */
/*   Updated: 2021/01/29 17:22:40 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	put_strerr(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
}

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

void	rd_stdin_wr(int f_dest, int buff_size)
{
	int		read_size;
	char	buff[buff_size + 1];

	while ((read_size = read(0, buff, buff_size)) != 0)
		buff[read_size] = 0;
	write(f_dest, 0, 1);
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

void	display(int ac, char **av)
{
	int	i;
	int	offset;

	// if we only have 'tail -c nb' the source is the stdin
	if (ac == 3)
	{
		rd_stdin_wr(1, 29998);
		return ;
	}
	// else the sources are all the given files
	i = 3;
	offset = ft_atoi(av[2]);
	while (i < ac)
	{
		o_rd_wr_c(av[i], 1, get_size(av[i], 29998) - offset, offset);
		i++;
	}
}

void	write_file(int ac, char **av, int i_op, int op)
{
	int	i;
	int	fd_dest;
	int	offset;

	if (op == 1)
		fd_dest = open(av[i_op + 1], O_WRONLY | O_CREAT);
	else
		fd_dest = open(av[i_op + 1], O_RDWR | O_CREAT | O_APPEND);
	if (fd_dest == -1)
	{
		put_strerr(strerror(errno));
		return ;
	}
	// if we have 'tail -c nb > file' the source is the stdin
	if (ac == 5)
	{
		rd_stdin_wr(fd_dest, 29998);
		return ;
	}
	// else the sources are all the other files
	i = 3;
	offset = ft_atoi(av[2]);
	while (i < ac)
	{
		if (i != i_op && i != i_op + 1)
			o_rd_wr_c(av[i], fd_dest, get_size(av[i], 29998) - offset, offset);
		i++;
	}
	if (close(fd_dest) == -1)
		put_strerr(strerror(errno));
}
