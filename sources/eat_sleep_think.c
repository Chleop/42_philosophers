/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:39 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/01 11:46:55 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if ((time_left(philo) >= 0) && (!philo->data->stop))
	{
		printf("%ld %d is eating\n", ft_time(), philo->id);
		philo->nb_meals++;
		if (philo->nb_meals == philo->data->max_meals)
			philo->data->count_full++;
		philo->last_meal = ft_time();
		usleep(1000 * philo->data->tt_eat);
	}
	return ;
}

void	ft_sleep(t_philo *philo)
{
	if (!philo->data->stop)
	{
		printf("%ld %d is sleeping\n", ft_time(), philo->id);
		if (philo->data->nb_ph % 2 == 0)
		{
			if ((time_left(philo) >= philo->data->tt_eat)
				&& (time_left(philo) >= philo->data->tt_sleep))
				usleep(1000 * (philo->data->tt_sleep));
			else if (!philo->data->stop)
				usleep(1000 * time_left(philo));
		}
		else
		{
			if ((time_left(philo) >= philo->data->tt_eat)
				&& (time_left(philo) >= (2 * philo->data->tt_sleep)))
				usleep(1000 * (philo->data->tt_sleep));
			else if (!philo->data->stop)
				usleep(1000 * time_left(philo));
		}
	}
	return ;
}

void	ft_think(t_philo *philo)
{
	if ((time_left(philo) >= 0) && (!philo->data->stop))
		printf("%ld %d is thinking\n", ft_time(), philo->id);
	return ;
}
