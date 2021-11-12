/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:24:15 by svieira           #+#    #+#             */
/*   Updated: 2021/11/12 13:27:16 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_float(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

int	invalid_input(int ac, char **av)
{
	if (ac == 2 && (av[1][0] == 'm' || av[1][0] == 'j') && av[1][1] == 0)
		return (0);
	if (ac == 4 && av[1][0] == 'j' && av[1][1] == 0 && is_float(av[2]) &&
		is_float(av[3]))
		return (0);
	return (1);
}

void	print_instructions(void)
{
	printf("Please provide the following parameters:\n\
	m - for displaying the Mandelbrot set\n\
	j - for displaying a Julia set\n");
	printf("For Julia set you may choose the constant c ");
	printf("by providing Re(c) and Im(c)\n\
	choose numbers between -1.0 and 1.0\n\
	e.g: ./fractol j 0.285 0\n");
}
