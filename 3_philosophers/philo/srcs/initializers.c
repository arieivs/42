/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:30 by svieira           #+#    #+#             */
/*   Updated: 2022/02/09 01:11:55 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	prepare_simulation(t_simulation *simulation,
			pthread_mutex_t *print_mutex)
{
	int	i;

	simulation->the_end = 0;
	simulation->printed_last_words = 0;
	pthread_mutex_init(print_mutex, NULL);
	simulation->print_mutex = print_mutex;
	simulation->nb_meals = (int *)malloc(sizeof(int) * simulation->n);
	if (!simulation->nb_meals)
		return (0);
	i = 0;
	while (i < simulation->n)
		simulation->nb_meals[i++] = 0;
	return (1);
}

t_fork	*forks_init(int n)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * n);
	if (!forks)
		return (NULL);
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

	if (!forks)
		return (NULL);
	philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* simulation->n);
	if (!philosophers)
		return (NULL);
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
