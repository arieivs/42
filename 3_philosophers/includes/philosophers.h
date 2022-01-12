/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:58:14 by svieira           #+#    #+#             */
/*   Updated: 2022/01/12 20:54:21 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_simu_data
{
	int	n;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_nb_meals;
}				t_simu_data;

typedef struct s_fork
{
	int				id; // for debugging purposes
	pthread_mutex_t	mutex;
	int				taken;
}				t_fork;

typedef struct s_philosopher
{
	int			id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_nb_meals; // not sure I'll need this one
	long int	time_of_death;
}				t_philosopher;

/* INTERFACE */
int				validate_input_into_struct(int ac, char **av, t_simu_data *sim);

/* INITIALIZERS */
t_fork			*forks_init(int n);
t_philosopher	*philosophers_init(int n, t_fork *forks);

/* UTILS */
int				str_is_digits(char *str);
int				ft_atoi(const char *str);

#endif
