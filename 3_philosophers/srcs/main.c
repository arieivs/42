/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 20:55:17 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(void *confusing_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)confusing_philosopher;
	// live
	// call eat, sleep, think
	printf("Philosopher %d ", philosopher->id);
	printf("has forks %d and %d\n", philosopher->left_fork->id, philosopher->right_fork->id);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_simu_data		simulation_data;
	t_fork			*forks;
	t_philosopher	*philosophers;
	pthread_t		*threads;
	int				i;

	if (!validate_input_into_struct(ac, av, &simulation_data))
		return (1); 
	forks = forks_init(simulation_data.n);
	philosophers = philosophers_init(simulation_data.n, forks);
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
	return (0);
}
