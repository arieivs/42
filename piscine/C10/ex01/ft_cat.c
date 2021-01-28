/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:42:58 by svieira           #+#    #+#             */
/*   Updated: 2021/01/28 12:02:57 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	rd_wr(int fd_src, int fd_dest, int buff_size)
{
	int		read_size;
	char	buff[buff_size + 1];

	while ((read_size = read(fd_src, buff, buff_size)) != 0)
	{
		buff[read_size] = 0;
		write(fd_dest, buff, read_size);
	}
}

void	o_rd_wr_c(char *path_src, int fd_dest, int buff_size)
{
	int	fd_src;

	fd_src = open(path_src, O_RDONLY);
	if (fd_src == -1)
	{
		write(2, "No such file or directory\n", 26);
		return ;
	}
	rd_wr(fd_src, fd_dest, buff_size);
	if (close(fd_src) == -1)
		write(2, "Could not close the file\n", 25);
}

void	display(int ac, char **av)
{
	int	i;
	int	buff_size;

	buff_size = 30;
	// if we only have 'cat' the source is the stdin
	if (ac == 1)
		rd_wr(0, 1, buff_size);
	// else the sources are all the given files
	i = 1;
	while (i < ac)
	{
		o_rd_wr_c(av[i], 1, buff_size);
		i++;
	}
}

void	write_file(int ac, char **av, int i_op, int op)
{
	int	i;
	int	fd_dest;
	int	buff_size;

	if (op == 1)
		fd_dest = open(av[i_op + 1], O_WRONLY | O_CREAT);
	else
		fd_dest = open(av[i_op + 1], O_RDWR | O_CREAT | O_APPEND);
	if (fd_dest == -1)
	{
		write(2, "Could not open the destination file\n", 36);
		return ;
	}
	buff_size = 30;
	// if we have 'cat > file' the source is the stdin
	if (ac == 3)
		rd_wr(1, fd_dest, buff_size);
	// else the sources are all the other files
	i = 1;
	while (i < ac)
	{
		if (i != i_op && i != i_op + 1)
			o_rd_wr_c(av[i], fd_dest, buff_size);
		i++;
	}
	if (close(fd_dest) == -1)
		write(2, "Could not close the destination file\n", 37);
}

int		is_op(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '>')
			return (0);
		i++;
	}
	if (i == 1)
		return (1);
	if (i == 2)
		return (2);
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int action;

	if (is_op(av[ac - 1]))
		return (-1);
	// actions - 0: display(stdout)  1: overwrite(files)  2: append(files)
	i = 1;
	while (i < ac)
	{
		if ((action = is_op(av[i])) != 0)
			break ;
		i++;
	}
	if (action)
		write_file(ac, av, i, action);
	else
		display(ac, av);
	return (0);
}
