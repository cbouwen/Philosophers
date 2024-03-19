/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:36:18 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/19 11:34:31 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	detach_all(t_philosopher philosopher[])
{
	int		i;

	i = -1;
	while (++i < philosopher[0].params->philos)
		pthread_detach(philosopher[i].philothread);
	usleep (50);
}

int monitoring(t_philosopher philosopher[])
{
    int i;

    while (1) 
    {   
        i = -1; 
        while (++i < philosopher[0].params->philos)
        {
            if (has_died(philosopher[i]) == 1) //add lock to has_died
            {
				detach_all(philosopher);
				log_action("has died", philosopher[i]);
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

