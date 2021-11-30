/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:39:57 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/30 10:49:26 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_data(char **argv, t_data *data)
{
	data->nb_ph = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	if (((data->nb_ph) <= 0) || ((data->tt_die) <= 0)
		|| ((data->tt_eat) <= 0) || ((data->tt_sleep) <= 0))
		return (0);
	data->philo = malloc (sizeof(t_philo) * data->nb_ph);
	if (!(data->philo))
		return (0);
	data->fork = malloc (sizeof(pthread_mutex_t) * data->nb_ph);
	if (!(data->fork))
		return (0);
	data->count_full = 0;
	data->stop = 0;
	return (1);
}

int	initialize_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}
