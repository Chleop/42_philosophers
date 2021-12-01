/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:24:25 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/01 17:07:02 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_both_forks(t_philo *philo)
{
	if (philo->id == 1)
		pthread_mutex_unlock(&(philo->data->fork[philo->data->nb_ph - 1]));
	else
		pthread_mutex_unlock(&(philo->data->fork[philo->id - 2]));
	pthread_mutex_unlock(&(philo->data->fork[philo->id - 1]));
}

int	lock_both_forks(t_philo *philo)
{
	int	last_fork;

	last_fork = philo->data->nb_ph - 1;
	if ((time_left(philo) >= 0) && (!philo->data->stop))
	{
		pthread_mutex_lock(&(philo->data->fork[philo->id - 1]));
		printf("%ld %d has taken a fork\n", current_time(philo), philo->id);
		if ((time_left(philo) >= 0) && (!philo->data->stop)
			&& (philo->data->nb_ph != 1))
		{
			if (philo->id != 1)
				pthread_mutex_lock(&(philo->data->fork[philo->id - 2]));
			else
				pthread_mutex_lock(&(philo->data->fork[last_fork]));
			printf("%ld %d has taken a fork\n", current_time(philo), philo->id);
			return (1);
		}
		else
			pthread_mutex_unlock(&(philo->data->fork[philo->id - 1]));
	}
	return (0);
}
