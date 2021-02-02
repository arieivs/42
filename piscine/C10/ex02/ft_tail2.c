/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:38:12 by svieira           #+#    #+#             */
/*   Updated: 2021/02/02 12:47:48 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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

int		invalid_input(int ac, char **av)
{
	int i;

	if (ac < 3 || av[1][0] != '-' || av[1][1] != 'c' || av[1][2] != 0)
	{
		put_strerr("option -c followed by offset is required");
		return (1);
	}
	i = 0;
	if (is_signal(av[2][0]))
		i++;
	while (av[2][i])
	{
		if (!is_number(av[2][i]))
		{
			put_strerr("illegal offset, a number is required");
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int	action;

	if (invalid_input(ac, av))
		return (1);
	i = 3;
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
