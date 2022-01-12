/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:39 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 20:27:40 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validate_input_into_struct(int ac, char **av, t_simu_data *simulation_data)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!str_is_digits(av[i]))
			return (0);
		i++;
	}
	simulation_data->n = ft_atoi(av[1]);
	simulation_data->time_to_die = ft_atoi(av[2]);
	simulation_data->time_to_eat = ft_atoi(av[3]);
	simulation_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		simulation_data->max_nb_meals = ft_atoi(av[5]);
	// should do a simplified atoi
	// check nb philosophers <= 200 ?
	// check times >= 60ms ?
	// give error messages?
	return (1);
}

