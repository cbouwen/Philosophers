/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:43:09 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/26 17:09:15 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	neg = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10;
		result = result + nptr[i] - '0';
		i++;
	}
	return (result * neg);
}

void	log_action(char *str, t_philosopher philosopher)
{
	long	time;

	pthread_mutex_lock(&philosopher.params->display);
	time = calculate_time(philosopher);
	printf("%ld %i %s\n", time, philosopher.id, str);
	pthread_mutex_unlock(&philosopher.params->display);
}

long	calculate_time(t_philosopher philosopher)
{
	struct timeval	t;
	long			time;

	gettimeofday(&t, NULL);
	time = -(philosopher.params->t_0 - ((t.tv_sec * 1000) + (t.tv_usec
					/ 1000)));
	return (time);
}

long	calculate_start_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
