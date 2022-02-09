/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requiem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:23:46 by svieira           #+#    #+#             */
/*   Updated: 2022/02/09 01:24:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	cleanup_threads_error(pthread_t *threads)
{
	free(threads);
	return (1);
}

void	cleanup(t_simulation *simulation, t_fork *forks,
			t_philosopher *philosophers)
{
	int	i;

	if (philosophers)
		free(philosophers);
	if (forks)
	{
		i = 0;
		while (i < simulation->n)
			pthread_mutex_destroy(&(forks[i++].mutex));
		free(forks);
	}
	pthread_mutex_destroy(simulation->print_mutex);
	if (simulation->nb_meals)
		free(simulation->nb_meals);
}
