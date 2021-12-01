/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:39 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/01 17:04:30 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if ((time_left(philo) >= 0) && (!philo->data->stop))
	{
		printf("%ld %d is eating\n", current_time(philo), philo->id);
		philo->nb_meals++;
		if (philo->nb_meals == philo->data->max_meals)
			philo->data->count_full++;
		philo->last_meal = ft_time();
		ft_wait(philo->data->tt_eat);
	}
	return ;
}

// void	ft_sleep(t_philo *philo)
// {
// 	if (!philo->data->stop)
// 	{
// 		printf("%ld %d is sleeping\n", ft_time(), philo->id);
// 		if (philo->data->nb_ph % 2 == 0)
// 		{
// 			if ((time_left(philo) >= philo->data->tt_eat)
// 				&& (time_left(philo) >= philo->data->tt_sleep))
// 				ft_wait((philo->data->tt_sleep));
// 			else if (!philo->data->stop)
// 				ft_wait(time_left(philo));
// 		}
// 		else
// 		{
// 			if ((time_left(philo) >= philo->data->tt_eat)
// 				&& (time_left(philo) >= (2 * philo->data->tt_sleep)))
// 				ft_wait((philo->data->tt_sleep));
// 			else if (!philo->data->stop)
// 				ft_wait(time_left(philo));
// 		}
// 	}
// 	return ;
// }

void	ft_sleep(t_philo *philo)
{
	if ((!philo->data->stop) && (philo->data->nb_ph % 2 == 0))
	{
		printf("%ld %d is sleeping\n", current_time(philo), philo->id);
		if ((time_left(philo) >= philo->data->tt_eat)
			&& (time_left(philo) >= philo->data->tt_sleep)
			&& (!philo->data->stop))
			ft_wait(philo->data->tt_sleep);
		else if (!philo->data->stop)
			ft_wait(time_left(philo));
	}
	else if (!philo->data->stop)
	{
		printf("%ld %d is sleeping\n", current_time(philo), philo->id);
		if ((time_left(philo) >= philo->data->tt_eat)
			&& (time_left(philo) >= (2 * philo->data->tt_sleep))
			&& (!philo->data->stop))
			ft_wait(philo->data->tt_sleep);
		else if (!philo->data->stop)
			ft_wait(time_left(philo));
	}
	return ;
}

void	ft_think(t_philo *philo)
{
	if ((time_left(philo) >= 0) && (!philo->data->stop))
		printf("%ld %d is thinking\n", current_time(philo), philo->id);
	return ;
}
