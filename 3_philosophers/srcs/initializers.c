/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 22:46:21 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*forks_init(int n)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * n);
	i = 0;
	while (i < n)
	{
		forks[i].id = i + 1;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].taken = 0;
		i++;
	}
	return (forks);
}

t_philosopher	*philosophers_init(t_simu_data simulation_data, t_fork *forks,
				pthread_mutex_t *print_mutex)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) *
					simulation_data.n);
	i = 0;
	while (i < simulation_data.n)
	{
		philosophers[i].id = i + 1;
		if (i == 0)
			philosophers[i].left_fork = &forks[simulation_data.n - 1];
		else
			philosophers[i].left_fork = &forks[i - 1];
		philosophers[i].right_fork = &forks[i];
		philosophers[i].time_to_die = simulation_data.time_to_die;
		philosophers[i].time_to_eat = simulation_data.time_to_eat;
		philosophers[i].time_to_sleep = simulation_data.time_to_sleep;
		philosophers[i].max_nb_meals = simulation_data.max_nb_meals;
		philosophers[i].print_mutex = print_mutex;
		i++;
	}
	return (philosophers);
}
