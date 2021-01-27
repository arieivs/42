/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:42:58 by svieira           #+#    #+#             */
/*   Updated: 2021/01/27 11:40:45 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	open_read_write(char *path_src, int fd_dest, int buff_size)
{
	int		fd_src;
	char	buff[buff_size + 1];
	int		read_size;

	fd_src = open(path_src, O_RDONLY);
	if (fd_src == -1)
	{
		write(2, "No such file or directory\n", 26);
		return ;
	}
	while ((read_size = read(fd_src, buff, buff_size)) != 0)
	{
		buff[read_size] = 0;
		write(fd_dest, buff, read_size);
	}
	if (close(fd_src) == -1)
		write(2, "Could not close the file\n", 25);
}

void	display_files(int ac, char **av)
{
	int	i;
	int	buff_size;

	i = 1;
	buff_size = 30;
	while (i < ac)
	{
		open_read_write(av[i], 1, buff_size);
		i++;
	}
}

void	write_file(int ac, char **av, int i_op, int op)
{
	int	i;
	int	fd_dest;
	int	buff_size;

	if (op == 1)
		fd_dest = open(av[i_op + 1], O_WRONLY, O_CREAT);
	else
		fd_dest = open(av[i_op + 1], O_RDWR, O_CREAT, O_APPEND);
	if (fd_dest == -1)
	{
		write(2, "Could not open the destination file\n", 36);
		return ;
	}
	i = 1;
	buff_size = 30;
	while (i < ac)
	{
		if (i != i_op && i != i_op + 1)
			open_read_write(av[i], fd_dest, buff_size);
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
	if (ac == 1 || (ac == 3 && is_op(av[1])))
		action = 3;
	else
	{
		i = 1;
		while (i < ac)
		{
			if ((action = is_op(av[i])) != 0)
				break ;
			i++;
		}
	}
	if (action == 0)
		display_files(ac, av);
	else if (action == 1 || action == 2)
		write_file(ac, av, i, action);
	/*else if (action == 3)
		// stdin*/
	return (0);
}
