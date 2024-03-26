/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:29:11 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/26 15:03:14 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philodata
{
	int				philos;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				tt_musteat;
	long			t_0;
	pthread_mutex_t	display;
	pthread_mutex_t	die_lock;
}					t_philodata;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				locked;
}					t_fork;

typedef struct s_philosopher
{
	int				id;
	long			time;
	int				last_meal;
	int				number_of_meals;
	int				delay;
	pthread_t		philothread;
	t_philodata		*params;
	t_fork			*left_fork;
	t_fork			*right_fork;
}					t_philosopher;

int					monitoring(t_philosopher philosopher[]);
int					init_philodata(t_philodata *philodata, int argc,
						char **argv);
int					ft_atoi(const char *nptr);
void				philos(t_philodata *philodata, int a);
long				calculate_time(t_philosopher philosopher);
long				calculate_start_time(void);
void				destroy_mutexes(t_philodata *params, t_fork forks[]);
int					has_died(t_philosopher philosopher);
int					eaten_enough(t_philosopher philosopher);
void				log_action(char *str, t_philosopher philosopher);
void				thread_start(t_philosopher philosopher[]);

#endif
