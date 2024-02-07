/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:06 by cbouwen           #+#    #+#             */
/*   Updated: 2024/01/16 15:13:55 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_forks(t_philodata philodata, t_fork forks[])
{
	int	i;

	i = -1;
	while (++i < philodata.philos)
	{
		pthread_mutex_init(&forks[i].fork, NULL);
	}
}

void	init_philos(t_philodata *philodata, t_philosopher philosopher[],
		t_fork forks[])
{
	int	i;

	i = -1;
	while (++i < philodata->philos)
	{
		philosopher[i].id = i;
		philosopher[i].last_meal = 0;
		philosopher[i].number_of_meals = 0;
		philosopher[i].params = philodata;
		philosopher[i].left_fork = &forks[i];
		philosopher[i].right_fork = &forks[(i + 1) % philodata->philos];
		philosopher[i].time = calculate_time(philosopher[i]);
		philosopher[i].delay = 0;
	}
}

int	monitoring(t_philosopher philosopher[])
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philosopher[0].params->philos)
		{
			if (has_died(philosopher[i]) == 1)
			{
				i = -1;
				while (++i < philosopher[0].params->philos)
					pthread_detach(philosopher[i].philothread);
				return (1);
			}
			if (eaten_enough(philosopher[i]) == 0)
			{
				i = -1;
				while (++i < philosopher[0].params->philos)
					pthread_join(philosopher[i].philothread, NULL);
				return (2);
			}
		}
	}
}

void	philos(t_philodata *philodata, int a)
{
	t_philosopher	philosopher[5000];
	t_fork			forks[5000];

	memset(philosopher, 0, a * sizeof(t_philosopher));
	memset(forks, 0, a * sizeof(t_fork));
	init_forks(*philodata, forks);
	init_philos(philodata, philosopher, forks);
	thread_start(philosopher);
	monitoring(philosopher);
	destroy_mutexes(philosopher[0].params, forks);
}
