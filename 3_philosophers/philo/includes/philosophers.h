/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:58:14 by svieira           #+#    #+#             */
/*   Updated: 2022/02/09 12:59:22 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_simulation
{
	int				n;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_nb_meals;
	int				max_meals_defined;
	int				*nb_meals;
	int				the_end;
	int				printed_last_words;
	pthread_mutex_t	*print_mutex;
	long long		start_time;
}				t_simulation;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
	int				taken;
}				t_fork;

typedef struct s_philosopher
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_simulation	*simulation;
	long long		time_death;
}				t_philosopher;

typedef enum e_actions
{
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIED
}			t_actions;

/* INTERFACE */
int				validate_input_and_parse(int ac, char **av, t_simulation *sim);
void			print_instructions(void);
void			print_message(t_philosopher philo, long long time, int action);

/* INITIALIZERS */
int				prepare_simulation(t_simulation *sim, pthread_mutex_t *print);
t_fork			*forks_init(int n);
t_philosopher	*philosophers_init(t_simulation *simulation, t_fork *forks);

/* LIFE OF A PHILOSOPHER */
void			*live(void *confused_philosopher);
void			grab_fork(t_philosopher *philosopher);
void			eating(t_philosopher *philosopher);
void			sleeping(t_philosopher *philosopher);
void			thinking(t_philosopher *philosopher);

/* PURGATORY */
int				at_worlds_end(t_philosopher *philosopher);
int				someone_died(t_philosopher *philosopher);
int				everyone_fulfilled(t_philosopher *philosopher);

/* REQUIEM */
int				cleanup_threads_error(pthread_t *threads);
void			cleanup(t_simulation *sim, t_fork *forks, t_philosopher *phils);

/* UTILS */
int				str_is_digits(char *str);
int				ft_atoi(const char *str);
long long		get_time_ms(void);

#endif
