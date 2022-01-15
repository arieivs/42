/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/15 15:38:03 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_simulation(t_simulation *simulation, t_philosopher *philosophers)
{
	int				i;
	pthread_t		*threads;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * simulation->n);
	gettimeofday(&(simulation->start_time), NULL);
	while (i < simulation->n)
	{
		if (pthread_create(&threads[i], NULL, &live, (void *)&philosophers[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < simulation->n)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	free(threads);
	return (0);
}

int	main(int ac, char **av)
{
	t_simulation	simulation;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philosopher	*philosophers;
	int				i;

	if (!validate_input_and_parse(ac, av, &simulation))
		return (1);
	pthread_mutex_init(&print_mutex, NULL);
	simulation.print_mutex = &print_mutex;
	forks = forks_init(simulation.n);
	philosophers = philosophers_init(&simulation, forks);
	start_simulation(&simulation, philosophers);
	// should move clean up somewhere else?
	free(philosophers);
	i = 0;
	while (i < simulation.n)
		pthread_mutex_destroy(&(forks[i++].mutex));
	free(forks);
	pthread_mutex_destroy(&print_mutex);
	return (0);
}
