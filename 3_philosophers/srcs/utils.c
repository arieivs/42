/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:14:45 by svieira           #+#    #+#             */
/*   Updated: 2022/01/15 16:15:51 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	str_is_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	nb;

	i = 0;
	signal = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signal);
}

int	get_time_of_simulation(struct timeval start)
{
	struct timeval	now;
	long long		now_ms;
	long long		start_ms;

	gettimeofday(&now, NULL);
	now_ms = (long long)(now.tv_sec * 1000) + now.tv_usec / 1000;
	start_ms = (long long)(start.tv_sec * 1000) + start.tv_usec / 1000;
	return ((int)(now_ms - start_ms));
}
