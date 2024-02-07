/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:19:10 by cbouwen           #+#    #+#             */
/*   Updated: 2024/01/16 15:14:50 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_valid(t_philodata philodata)
{
	if (philodata.philos < 1 || philodata.philos > 5000)
		return (0);
	if (philodata.tt_die < 1)
		return (0);
	if (philodata.tt_eat < 1)
		return (0);
	if (philodata.tt_sleep < 1)
		return (0);
	if (philodata.tt_musteat < 1)
		return (0);
	return (1);
}

t_philodata	write_philodata(t_philodata *philodata, int argc, char **argv)
{
	philodata->philos = ft_atoi(argv[0]);
	philodata->tt_die = ft_atoi(argv[1]);
	philodata->tt_eat = ft_atoi(argv[2]);
	philodata->tt_eat *= 1000;
	philodata->tt_sleep = ft_atoi(argv[3]);
	philodata->tt_sleep *= 1000;
	if (argc == 5)
		philodata->tt_musteat = ft_atoi(argv[4]);
	else
		philodata->tt_musteat = INT_MAX;
	philodata->t_0 = calculate_start_time();
	pthread_mutex_init(&philodata->display, NULL);
	return (*philodata);
}

int	init_philodata(t_philodata *philodata, int argc, char **argv)
{
	if (check_digit(argc, argv) == 0)
		return (3);
	write_philodata(philodata, argc, argv);
	if (check_valid(*philodata) == 0)
		return (4);
	return (5);
}
