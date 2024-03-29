/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:39 by svieira           #+#    #+#             */
/*   Updated: 2022/02/09 15:10:58 by svieira          ###   ########.fr       */
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
	return (1);
}

void	print_instructions(void)
{
	printf("\nPHILOSOPHERS - How to run this programme:\n\n");
	printf("./philosophers <nb_philosophers> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> <nb_times_each_should_eat>\n\n");
	printf("- all arguments are numbers, only digits are allowed\n");
	printf("- times are given in miliseconds\n");
	printf("- do not test with nb_philosophers > 200\n");
	printf("- do not test with times < 60 ms\n\n");
}

void	print_message(t_philosopher philosopher, long long time, int action)
{
	int	timestamp;

	if (philosopher.simulation->printed_last_words)
		return ;
	if (philosopher.simulation->the_end && action == DIED)
		philosopher.simulation->printed_last_words = 1;
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
}
