/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:01:42 by svieira           #+#    #+#             */
/*   Updated: 2021/01/28 15:02:19 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

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
