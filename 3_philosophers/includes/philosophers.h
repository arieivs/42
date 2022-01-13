/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:58:14 by svieira           #+#    #+#             */
/*   Updated: 2022/01/13 14:43:18 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_simulation
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_nb_meals;
	pthread_mutex_t	*print_mutex;
	long int		start_time;
}				t_simulation;

typedef struct s_fork
{
	int				id; // for debugging purposes
	pthread_mutex_t	mutex;
	int				taken;
}				t_fork;

typedef struct s_philosopher
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_simulation	*simulation;
	long int		time_of_death;
}				t_philosopher;

/* INTERFACE */
int				validate_input_and_parse(int ac, char **av, t_simulation *sim);
int				print(t_philosopher philosopher);

/* INITIALIZERS */
t_fork			*forks_init(int n);
t_philosopher	*philosophers_init(t_simulation *simulation, t_fork *forks);

/* LIFE OF A PHILOSOPHER */
void			*live(void *confused_philosopher);

/* UTILS */
int				str_is_digits(char *str);
int				ft_atoi(const char *str);

#endif
