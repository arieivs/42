/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:01 by svieira           #+#    #+#             */
/*   Updated: 2022/01/13 13:04:27 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(void *confused_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)confused_philosopher;
	// live
	// call eat, sleep, think
	print(*philosopher);
	return (NULL);
}

// grab fork
void	grab_fork(t_philosopher *philosopher)
{
	while (1)
	{
		if (!philosopher->left_fork->taken && !philosopher->right_fork->taken)
			break ;
	}
	pthread_mutex_lock(&philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->right_fork->mutex);
	//get timestamp -> need to know when did the simulation start right
	//print message
}

// eat

// sleep

// think
