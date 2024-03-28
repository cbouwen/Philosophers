/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:19 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/26 17:03:23 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	monitor(t_philosopher philosopher[])
{
	int	i;

	i = -1;
	while (++i < philosopher[0].params->philos)
		pthread_join(philosopher[i].philothread, NULL);
	return (1);
}
