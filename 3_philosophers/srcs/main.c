/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 23:00:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_simu_data		simulation_data;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philosopher	*philosophers;
	pthread_t		*threads;
	int				i;

	if (!validate_input_into_struct(ac, av, &simulation_data))
		return (1);
	pthread_mutex_init(&print_mutex, NULL); // should add this to simu struct?
	forks = forks_init(simulation_data.n);
	philosophers = philosophers_init(simulation_data, forks, &print_mutex);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * simulation_data.n);
	i = 0;
	while (i < simulation_data.n)
	{
		if (pthread_create(&threads[i], NULL, &live, (void *)&philosophers[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < simulation_data.n)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	free(threads);
	free(philosophers);
	i = 0;
	while (i < simulation_data.n)
		pthread_mutex_destroy(&(forks[i++].mutex));
	free(forks);
	pthread_mutex_destroy(&print_mutex);
	return (0);
}
