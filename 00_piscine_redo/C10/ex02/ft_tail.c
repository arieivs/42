/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:42:58 by svieira           #+#    #+#             */
/*   Updated: 2021/02/02 21:03:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	display(int ac, char **av)
{
	int	i;
	int	offset;
	int file_size;

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
		file_size = get_size(av[i], 29998);
		if (offset > file_size)
			o_rd_wr_c(av[i], 1, 0, file_size);
		else
			o_rd_wr_c(av[i], 1, file_size - offset, offset);
		i++;
	}
}

void	header(char *path_src, int fd_dest)
{
	char *file_name;

	write(fd_dest, "\n==> ", 5);
	file_name = basename(path_src);
	while (*file_name)
	{
		write(fd_dest, file_name, 1);
		file_name++;
	}
	write(fd_dest, " <==\n", 5);
}

void	write_from_file(int ac, char **av, int i_op, int fd_dest)
{
	int i;
	int offset;
	int file_size;

	i = 3;
	offset = ft_atoi(av[2]);
	while (i < ac)
	{
		if (i != i_op && i != i_op + 1)
		{
			// if we have 'tail -c nb src_file > dest_file', no header is added
			// else there are more than one source file and a header is added
			if (ac != 6)
				header(av[i], fd_dest);
			file_size = get_size(av[i], 29998);
			if (offset > file_size)
				o_rd_wr_c(av[i], fd_dest, 0, file_size);
			else
				o_rd_wr_c(av[i], fd_dest, file_size - offset, offset);
			// when a header is added on top, a new line is added at the end
			// except for the last source file
			if (ac != 6 && !((i_op == ac - 2 && i == i_op - 1) || i == ac - 1))
				write(fd_dest, "\n", 1);
		}
		i++;
	}
}

void	write_file(int ac, char **av, int i_op, int op)
{
	int	fd_dest;

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
	// else the sources are all the other files
	if (ac == 5)
		rd_stdin_wr(fd_dest, 29998);
	else
		write_from_file(ac, av, i_op, fd_dest);
	if (close(fd_dest) == -1)
		put_strerr(strerror(errno));
}
