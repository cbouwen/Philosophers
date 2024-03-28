/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:34:45 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/26 16:55:29 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	thread_start(t_philosopher philosopher[])
{
	int	i;

	i = 0;
	while (i < philosopher[0].params->philos)
	{
		pthread_create(&philosopher[i].philothread, NULL, start,
			&philosopher[i]);
		i++;
	}
}

void	destroy_mutexes(t_philodata *params, t_fork forks[])
{
	int	i;

	pthread_mutex_destroy(&params->display);
	i = -1;
	while (++i < params->philos)
	{
//		if (forks[i].locked == 1)
//			pthread_mutex_unlock(&forks[i].fork);
		pthread_mutex_destroy(&forks[i].fork);
	}
}
