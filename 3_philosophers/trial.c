/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:40:30 by svieira           #+#    #+#             */
/*   Updated: 2021/12/30 23:46:32 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo_data	philo_data_init(int id, pthread_mutex_t *right_fork,
				pthread_mutex_t *left_fork)
{
	t_philo_data	philo_data;

	philo_data.id = id;
	philo_data.right_fork = right_fork;
	philo_data.left_fork = left_fork;
	return (philo_data);
}

void	*live(void *philo_data)
{
	// live
	// call eat, sleep, think
	printf("Philosopher %d\n", ((t_philo_data *)philo_data)->id);
	return (NULL);
}

int	main(void)
{
	int	n = 3; // which will come from argv later
	pthread_mutex_t	*forks;
	t_philo_data	*philos_data;
	pthread_t		*philos_threads;
	int				i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	i = 0;
	while (i < n)
		pthread_mutex_init(&forks[i++], NULL);
	philos_data = (t_philo_data *)malloc(sizeof(t_philo_data) * n);
	philos_threads = (pthread_t *)malloc(sizeof(pthread_t) * n);
	i = 0;
	while (i < n)
	{
		if (i == 0)
			philos_data[i] = philo_data_init(i + 1, &forks[n - 1], &forks[0]);
		else
			philos_data[i] = philo_data_init(i + 1, &forks[i - 1], &forks[i]);
		if (pthread_create(&philos_threads[i], NULL, &live,
			(void *)&philos_data[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (pthread_join(philos_threads[i], NULL))
			return (1);
		i++;
	}
	free(philos_threads);
	free(philos_data);
	i = 0;
	while (i < n)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
	return (0);
}
