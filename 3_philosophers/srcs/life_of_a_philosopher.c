/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:59:01 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 23:02:24 by svieira          ###   ########.fr       */
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

// eat

// sleep

// think
