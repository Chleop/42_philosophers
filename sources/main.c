/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:35:10 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/02 18:38:52 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_data(char **argv, t_data *data)
{
	data->philo = NULL;
	data->fork = NULL;
	data->nb_ph = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	if (((data->nb_ph) == 0) || ((data->tt_die) == 0)
		|| ((data->tt_eat) == 0) || ((data->tt_sleep) == 0)
		|| ((data->max_meals) == 0))
		return (0);
	data->philo = malloc (sizeof(t_philo) * data->nb_ph);
	if (!(data->philo))
		return (0);
	data->fork = malloc (sizeof(pthread_mutex_t) * data->nb_ph);
	if (!(data->fork))
		return (0);
	data->stop = 0;
	data->start_time = ft_time();
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if ((argc < 5) || (argc > 6))
	{
		ft_putstr("Error: Must give 4 or 5 arguments\n");
		return (1);
	}
	data = malloc (sizeof(t_data) * 1);
	if ((!data) || (!initialize_data(argv, data)) || (!initialize_mutex(data))
		|| (!create_philos(data)) || (!destroy_mutex(data)))
	{
		ft_putstr("Error\n");
		ft_free(&data);
		return (1);
	}
	ft_free(&data);
	return (0);
}
