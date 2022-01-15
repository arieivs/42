/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:01 by svieira           #+#    #+#             */
/*   Updated: 2022/01/15 18:49:19 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(void *confused_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)confused_philosopher;
	// call grab_fork only for some, and think for the others?
	grab_fork(philosopher);
	return (NULL);
}

void	grab_fork(t_philosopher *philosopher)
{
	long long	took_fork_time;

	while (philosopher->left_fork->taken || philosopher->right_fork->taken)
	{
		// if philosopher died
			// break ; or... exit to die
	}
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	took_fork_time = get_time_ms();
	print_message(*philosopher, took_fork_time, FORK);
	eat(philosopher);
}

void	eat(t_philosopher *philosopher)
{
	long long	start_eat;

	start_eat = get_time_ms();
	print_message(*philosopher, start_eat, EAT);
	while (get_time_ms() < (start_eat + philosopher->simulation->time_to_eat))
	{
		// check if philosopher died
	}
	philosopher->time_of_death = get_time_ms() +
		philosopher->simulation->time_to_die;  
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	sleep(philosopher);
}

void	sleep(t_philosopher *philosopher)
{
	long long	start_sleep;

	start_sleep = get_time_ms();
	print_message(*philosopher, start_sleep, SLEEP);
	while (get_time_ms() < start_sleep + philosopher->simulation->time_to_sleep)
	{
		// check if philosopher died
	}
	think(philosopher);
}

void	think(t_philosopher *philosopher)
{
	long long	start_think;

	start_think = get_time_ms();
	print_message(*philosopher, start_think, THINK);
	// add usleep(1)? msessa
	grab_fork(philosopher);
}
