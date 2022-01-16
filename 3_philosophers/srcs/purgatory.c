/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purgatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:01:36 by svieira           #+#    #+#             */
/*   Updated: 2022/01/16 21:01:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
