/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/13 13:04:46 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_simulation	simulation;
	t_fork			*forks;
	t_philosopher	*philosophers;
	pthread_t		*threads;
	int				i;

	if (!validate_input_and_parse(ac, av, &simulation))
		return (1);
	forks = forks_init(simulation.n);
	philosophers = philosophers_init(&simulation, forks);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * simulation.n);
	simulation_init(&simulation);
	i = 0;
	while (i < simulation.n)
	{
		if (pthread_create(&threads[i], NULL, &live, (void *)&philosophers[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < simulation.n)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	// should move clean up somewhere else
	free(threads);
	free(philosophers);
	i = 0;
	while (i < simulation.n)
		pthread_mutex_destroy(&(forks[i++].mutex));
	free(forks);
	pthread_mutex_destroy(simulation.print_mutex);
	return (0);
}
