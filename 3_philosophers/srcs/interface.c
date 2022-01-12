/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:39 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 22:53:35 by svieira          ###   ########.fr       */
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

int	print(t_philosopher philosopher)
{
	pthread_mutex_lock(philosopher.print_mutex);
	printf("Philosopher %d ", philosopher.id);
	printf("has forks %d and %d\n", philosopher.left_fork->id, philosopher.right_fork->id);
	pthread_mutex_unlock(philosopher.print_mutex);
	return (0);
}
