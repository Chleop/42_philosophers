/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:39 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/30 11:05:40 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (((ft_time() - philo->last_meal) <= philo->data->tt_die) && (!philo->data->stop))
	{
		printf("%ld %d has taken a fork\n", ft_time(), philo->id);
		printf("%ld %d has taken a fork\n", ft_time(), philo->id);
		printf("%ld %d is eating\n", ft_time(), philo->id);
		philo->nb_meals++;
		if (philo->nb_meals == philo->data->max_meals)
			philo->data->count_full++;
		philo->last_meal = ft_time();
		usleep(1000 * philo->data->tt_eat);
	}
	return;
}

void	ft_sleep(t_philo *philo)
{
	long	time_unlapsed;
	
	if (!philo->data->stop)
	{
		printf("%ld %d is sleeping\n", ft_time(), philo->id);
		time_unlapsed = ft_time() - philo->last_meal;
		if ((time_unlapsed + philo->data->tt_sleep) > philo->data->tt_die)
			usleep(1000 * (philo->data->tt_die - time_unlapsed));
		else
			usleep(1000 * (philo->data->tt_sleep - (time_unlapsed - philo->data->tt_eat)));
	}
	return ;
}

void	ft_think(t_philo *philo)
{
	if (!philo->data->stop)
	{
		printf("%ld %d is thinking\n", ft_time(), philo->id);
	}
	return ;
}
