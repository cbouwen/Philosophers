/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:26:06 by cbouwen           #+#    #+#             */
/*   Updated: 2024/01/16 15:04:43 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_error(int a)
{
	if (a == 1)
		printf("You need to add more arguments\n");
	if (a == 2)
		printf("You need to add less arguments\n");
	if (a == 3)
		printf("All the arguments have to be digits\n");
	if (a == 4)
		printf("The scope of your arguments is incorrect\n");
}

int	error_check(t_philodata *philodata, int argc, char **argv)
{
	int	a;

	a = 0;
	if (argc < 4)
		a = 1;
	if (argc > 5)
		a = 2;
	if (a == 0)
		a = init_philodata(philodata, argc, argv);
	return (a);
}

int	main(int argc, char **argv)
{
	t_philodata	philodata;
	int			a;

	a = error_check(&philodata, argc - 1, argv + 1);
	if (a != 5)
		ft_error(a);
	else
		philos(&philodata, philodata.philos);
}
