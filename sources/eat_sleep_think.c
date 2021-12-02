/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:39 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/02 19:08:11 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	printf("%ld %d is eating\n", current_time(philo), philo->id);
	philo->nb_meals++;
	if (philo->nb_meals == philo->data->max_meals)
		one_more_full(philo);
	philo->last_meal = ft_time();
	if (philo->data->tt_eat >= philo->data->tt_die)
		return ;
	ft_wait(philo->data->tt_eat);
	return ;
}

void	ft_sleep(t_philo *philo)
{
	if ((!should_end(philo)) && (philo->data->nb_ph % 2 == 0))
	{
		printf("%ld %d is sleeping\n", current_time(philo), philo->id);
		if (((time_left(philo) >= philo->data->tt_eat)
			&& (!should_end(philo)))
			&& ((time_left(philo) >= philo->data->tt_sleep)
			|| (philo->data->max_meals == 1)))
			ft_wait(philo->data->tt_sleep);
		else if (!should_end(philo))
			ft_wait(time_left(philo) + 1);
	}
	else if (!should_end(philo))
	{
		printf("%ld %d is sleeping\n", current_time(philo), philo->id);
		if (((time_left(philo) >= philo->data->tt_sleep)
			&& (!should_end(philo))) && ((philo->data->max_meals == 1)
				|| (time_left(philo) >= (2 * philo->data->tt_eat))))
				ft_wait(philo->data->tt_sleep);
		else if (!should_end(philo))
			ft_wait(time_left(philo) + 1);
	}
	return ;
}

void	ft_think(t_philo *philo)
{
	if (!should_end(philo))
		printf("%ld %d is thinking\n", current_time(philo), philo->id);
	return ;
}
