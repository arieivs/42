/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:17:42 by svieira           #+#    #+#             */
/*   Updated: 2020/12/16 11:37:25 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char **av)
{
	int x;
	int y;
	int result;

	if (ac != 4)
		return (0);
	x = ft_atoi(av[1]);
	y = ft_atoi(av[3]);
	if (!ft_valid_op(y, av[2]))
		return (0);
	result = ft_do_op(x, y, av[2][0]);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
