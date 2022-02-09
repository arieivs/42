/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2022/02/09 01:37:49 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Getting start_time (and thus times of death for philosophers) only here
 * instead of in prepare_simulation and philosophers_init, in an attempty for
 * only starting the clock once the simulation really starts.
 * Might be the same, given how fast computers are.
 */
int	run_simulation(t_simulation *simulation, t_philosopher *philosophers)
{
	int				i;
	pthread_t		*threads;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * simulation->n);
	if (!threads)
		return (1);
	simulation->start_time = get_time_ms();
	while (i < simulation->n)
	{
		philosophers[i].time_death = simulation->start_time
			+ simulation->time_to_die;
		if (pthread_create(&threads[i], NULL, &live, (void *)&philosophers[i]))
			return (cleanup_threads_error(threads));
		i++;
	}
	i = 0;
	while (i < simulation->n)
	{
		if (pthread_join(threads[i], NULL))
			return (cleanup_threads_error(threads));
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
	int				r;

	if (!validate_input_and_parse(ac, av, &simulation))
	{
		print_instructions();
		return (1);
	}
	if (prepare_simulation(&simulation, &print_mutex))
	{
		forks = forks_init(simulation.n);
		philosophers = philosophers_init(&simulation, forks);
		r = 1;
		if (forks && philosophers)
			r = run_simulation(&simulation, philosophers);
		cleanup(&simulation, forks, philosophers);
		return (r);
	}
	cleanup(&simulation, NULL, NULL);
	return (1);
}
