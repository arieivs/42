/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:01 by svieira           #+#    #+#             */
/*   Updated: 2022/01/16 19:52:05 by svieira          ###   ########.fr       */
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

/* Added small delay (1ms) between determining one's death and announcing it.
 * This solved the issue of having 2 deaths announcements when 2 philosophers
 * died at exactly the same time.
 * What I think: given usleep unaccuracy, it enlarges the gap between the 2
 * print_message(..., DIED) function calls.
 * I believe it will also help in case any other message arrives at the same
 * time as a death one, allowing the other to be processed first.
 */
int	someone_died(t_philosopher *philosopher)
{
	long long	check_vital_signs;

	if (philosopher->simulation->someone_died)
		return (1);
	check_vital_signs = get_time_ms();
	if (philosopher->time_death <= check_vital_signs)
	{
		philosopher->simulation->someone_died = 1;
		usleep(1000);
		print_message(*philosopher, check_vital_signs, DIED);
		return (1);
	}
	return (0);
}

int	everyone_fulfilled(t_philosopher *philosopher)
{
	int	i;

	if (!philosopher->simulation->max_meals_defined)
		return (0);
	if (philosopher->simulation->everyone_fulfilled)
		return (1);
	i = 0;
	while (i < philosopher->simulation->n)
	{
		if (philosopher->simulation->nb_meals[i] <
			philosopher->simulation->max_nb_meals)
			return (0);
		i++;
	}
	philosopher->simulation->everyone_fulfilled = 1;
	return (1);
}

/* Checking if neither fork is taken before locking the mutexes to prevent
 * dead locks.
 * Else one philosopher A may lock the fork on its left and then wait for a
 * while until the right fork is available.
 * In the meantime philosopher B could have been eating with the first fork
 * A locked, but instead was waiting as well.
 * Ideally, this would be checked with mutex_trylock function (which tries to
 * lock it just once and returns whether it was successful or not), but it's a
 * forbidden function for this project.
 *
 * If n=1, the left_fork is NULL, thus it will stay in the loop until it dies.
 */
void	grab_fork(t_philosopher *philosopher)
{
	long long	took_fork_time;

	while (!philosopher->left_fork || philosopher->left_fork->taken ||
		philosopher->right_fork->taken)
	{
		if (someone_died(philosopher) || everyone_fulfilled(philosopher))
			return ;
	}
	philosopher->left_fork->taken = 1;
	philosopher->right_fork->taken = 1;
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	took_fork_time = get_time_ms();
	print_message(*philosopher, took_fork_time, FORK);
	eating(philosopher);
}

/* To be fulfilled they need to finish eating that one last time -> right?
 */
void	eating(t_philosopher *philosopher)
{
	long long	start_eat;

	start_eat = get_time_ms();
	philosopher->time_death = start_eat + philosopher->simulation->time_to_die;
	print_message(*philosopher, start_eat, EAT);
	//printf("%d should die %lld %d\n", philosopher->id, philosopher->time_death, (int)(philosopher->time_death - philosopher->simulation->start_time));
	while (get_time_ms() < (start_eat + philosopher->simulation->time_to_eat))
	{
		if (someone_died(philosopher) || everyone_fulfilled(philosopher))
			return ;
	}
	if (philosopher->simulation->max_meals_defined)
		philosopher->simulation->nb_meals[philosopher->id - 1] += 1;
	sleeping(philosopher);
}

/* Decided to unlock the forks mutex only once they start sleeping
 * instead of doing it at the end of eating function
 * because I was receiving the message "xxx 2 has taken a fork"
 * before "xxx 1 is sleeping"
 * the timestamp xxx was exactly the same so it was correct, the fork was free
 * but it was confusing for the user
 */
void	sleeping(t_philosopher *philosopher)
{
	long long	start_sleep;

	start_sleep = get_time_ms();
	print_message(*philosopher, start_sleep, SLEEP);
	pthread_mutex_unlock(&philosopher->left_fork->mutex);
	pthread_mutex_unlock(&philosopher->right_fork->mutex);
	philosopher->left_fork->taken = 0;
	philosopher->right_fork->taken = 0;
	while (get_time_ms() < start_sleep + philosopher->simulation->time_to_sleep)
	{
		if (someone_died(philosopher) || everyone_fulfilled(philosopher))
			return ;
	}
	thinking(philosopher);
}

void	thinking(t_philosopher *philosopher)
{
	long long	start_think;

	start_think = get_time_ms();
	print_message(*philosopher, start_think, THINK);
	usleep(1000); //explain or remove, check if really necessary
	grab_fork(philosopher);
}
