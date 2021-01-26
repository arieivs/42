/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:39:43 by svieira           #+#    #+#             */
/*   Updated: 2021/01/26 16:06:23 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_display_file(char *path, int buff_size)
{
	int		fd;
	char	buff[buff_size + 1];
	int		read_size;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while ((read_size = read(fd, buff, buff_size)) != 0)
	{
		buff[read_size] = 0;
		write(1, buff, read_size);
	}
	if (close(fd) == -1)
		write(2, "Cannot close file.\n", 19);
}

int		main(int ac, char **av)
{
	int buff_size;

	if (ac != 2)
	{
		if (ac == 1)
			write(2, "File name missing.\n", 19);
		else
			write(2, "Too many arguments.\n", 20);
		return (0);
	}
	buff_size = 10;
	ft_display_file(av[1], buff_size);
	return (0);
}
