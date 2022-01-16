/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:39 by svieira           #+#    #+#             */
/*   Updated: 2022/01/16 19:26:35 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validate_input_and_parse(int ac, char **av, t_simulation *simulation)
{
	int	i;

	if (ac != 5 && ac != 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!str_is_digits(av[i]))
			return (0);
		i++;
	}
	simulation->n = ft_atoi(av[1]);
	simulation->time_to_die = ft_atoi(av[2]);
	simulation->time_to_eat = ft_atoi(av[3]);
	simulation->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		simulation->max_meals_defined = 1;
		simulation->max_nb_meals = ft_atoi(av[5]);
	}
	else
		simulation->max_meals_defined = 0;
	// should do a simplified atoi
	// check nb philosophers <= 200 ?
	// check times >= 60ms ?
	// give error messages?
	return (1);
}

int	print_message(t_philosopher philosopher, long long time, int action)
{
	int	timestamp;

	if (philosopher.simulation->printing_obituary)
		return (0);
	if (action == DIED)
		philosopher.simulation->printing_obituary = 1;
	pthread_mutex_lock(philosopher.simulation->print_mutex);
	timestamp = (int)(time - philosopher.simulation->start_time);
	printf("%d %d ", timestamp, philosopher.id);
	if (action == DIED)
		printf("died\n");
	else if (action == FORK)
		printf("has taken a fork\n");
	else if (action == EAT)
		printf("is eating\n");
	else if (action == SLEEP)
		printf("is sleeping\n");
	else if (action == THINK)
		printf("is thinking\n");
	pthread_mutex_unlock(philosopher.simulation->print_mutex);
	return (0);
}
