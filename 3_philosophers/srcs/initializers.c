/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/19 12:48:13 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	prepare_simulation(t_simulation *simulation,
			pthread_mutex_t *print_mutex)
{
	int	i;

	simulation->nb_meals = (int *)malloc(sizeof(int) * simulation->n);
	i = 0;
	while (i < simulation->n)
		simulation->nb_meals[i++] = 0;
	simulation->the_end = 0;
	simulation->printed_last_words = 0;
	pthread_mutex_init(print_mutex, NULL);
	simulation->print_mutex = print_mutex; 
}

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
		if (simulation->n == 1)
			philosophers[i].left_fork = NULL;
		else if (i == 0)
			philosophers[i].left_fork = &forks[simulation->n - 1];
		else
			philosophers[i].left_fork = &forks[i - 1];
		philosophers[i].right_fork = &forks[i];
		philosophers[i].simulation = simulation;
		i++;
	}
	return (philosophers);
}
