/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/15 18:04:09 by svieira          ###   ########.fr       */
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

t_philosopher	*philosophers_init(t_simulation *simulation, t_fork *forks)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) *
					simulation->n);
	i = 0;
	while (i < simulation->n)
	{
		philosophers[i].id = i + 1;
		if (i == 0)
			philosophers[i].left_fork = &forks[simulation->n - 1];
		else
			philosophers[i].left_fork = &forks[i - 1];
		philosophers[i].right_fork = &forks[i];
		philosophers[i].simulation = simulation;
		philosophers[i].time_of_death = simulation->start_time +
										simulation->time_to_die;
		i++;
	}
	return (philosophers);
}
