/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:17:31 by cbouwen           #+#    #+#             */
/*   Updated: 2024/02/07 16:17:52 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eating(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork->fork);
	log_action("has taken a fork", *philosopher);
	pthread_mutex_lock(&philosopher->right_fork->fork);
	log_action("has taken a fork", *philosopher);
	log_action("is eating", *philosopher);
	philosopher->last_meal = calculate_time(*philosopher);
	usleep(philosopher->params->tt_eat);
	philosopher->number_of_meals++;
	pthread_mutex_unlock(&philosopher->left_fork->fork);
	pthread_mutex_unlock(&philosopher->right_fork->fork);
}

void	*action(void *philosopher)
{
	t_philosopher	*myphilosopher;

	myphilosopher = (t_philosopher *)philosopher;
	while (has_died(*myphilosopher) == 0)
	{
		if (myphilosopher->delay == 0 && myphilosopher->id % 2 == 1)
		{
			usleep(10000);
			myphilosopher->delay = 1;
		}
		eating(myphilosopher);
		if (eaten_enough(*myphilosopher) == 0)
			break ;
		log_action("is sleeping", *myphilosopher);
		usleep(myphilosopher->params->tt_sleep);
		log_action("is thinking", *myphilosopher);
	}
	return (NULL);
}

void	thread_start(t_philosopher philosopher[])
{
	int	i;

	i = 0;
	while (i < philosopher[0].params->philos)
	{
		pthread_create(&philosopher[i].philothread, NULL, action,
			&philosopher[i]);
		i++;
	}
}
