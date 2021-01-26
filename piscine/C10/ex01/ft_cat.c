/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:42:58 by svieira           #+#    #+#             */
/*   Updated: 2021/01/26 22:53:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void	display_files(int ac, char **av, int buff_size)
{
	int		i;
	int		fd;
	char	buff[buff_size + 1];
	int		read_size;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
		{
			write(2, "No such file or directory\n", 26);
			i++;
			continue ;
		}
		while ((read_size = read(fd, buff, buff_size)) != 0)
		{
			buff[read_size] = 0;
			write(1, buff, read_size);
		}
		if (close(fd) == -1)
			write(2, "Could not close the file\n", 25);
		i++;
	}
}

int	is_op(char *str)
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

int	main(int ac, char **av)
{
	int i;
	int action;
	int buff_size;

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
	buff_size = 30;
	if (action == 0)
		display_files(ac, av, buff_size);
	/*else if (action == 1)
		// overwrite
	else if (action == 2)
		// append
	else if (action == 3)
		// stdin*/
	return (0);
}
