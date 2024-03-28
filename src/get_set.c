/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:12:52 by cbouwen           #+#    #+#             */
/*   Updated: 2024/03/28 15:16:47 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);

}

bool    get_long(pthread_mutex_t *mutex, long *value)
{
    long    ret;

    pthread_mutex_lock(mutex);
    ret = *value;
    pthread_mutex_unlock(mutex);
    return (ret);
}

void    set_int(pthread_mutex_t *mutex, int *dest, int value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);

}

int    get_int(pthread_mutex_t *mutex, int *value)
{
    int    ret;

    pthread_mutex_lock(mutex);
    ret = *value;
    pthread_mutex_unlock(mutex);
    return (ret);
}

bool	simulation_finished(t_philodata *philodata)
{
	return (get_bool(&philodata->table_mutex, &philodata->end_simulation);
}
