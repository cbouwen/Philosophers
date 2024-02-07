/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:11:30 by cbouwen           #+#    #+#             */
/*   Updated: 2024/01/16 14:53:36 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	log_action(char *str, t_philosopher philosopher)
{
	long	time;

	pthread_mutex_lock(&philosopher.params->display);
	time = calculate_time(philosopher);
	printf("%ld %i %s\n", time, philosopher.id, str);
	pthread_mutex_unlock(&philosopher.params->display);
}

int	has_died(t_philosopher philosopher)
{
	long	ct;

	ct = calculate_time(philosopher);
	if (ct - philosopher.last_meal > philosopher.params->tt_die)
	{
		log_action("has died", philosopher);
		return (1);
	}
	return (0);
}

int	eaten_enough(t_philosopher philosopher)
{
	if (philosopher.params->tt_musteat == philosopher.number_of_meals)
		return (0);
	return (1);
}

void	destroy_mutexes(t_philodata *params, t_fork forks[])
{
	int	i;

	pthread_mutex_destroy(&params->display);
	i = -1;
	while (++i < params->philos)
		pthread_mutex_destroy(&forks[i].fork);
}
