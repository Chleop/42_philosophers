/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:24:25 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/02 13:05:09 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (pthread_mutex_init(&(data->mute_stop), NULL))
		return (0);
	return (1);
}

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
	if (!should_end(philo))
	{
		pthread_mutex_lock(&(philo->data->fork[philo->id - 1]));
		printf("%ld %d has taken a fork\n", current_time(philo), philo->id);
		if (!should_end(philo) && (philo->data->nb_ph != 1))
		{
			if (philo->id != 1)
				pthread_mutex_lock(&(philo->data->fork[philo->id - 2]));
			else
				pthread_mutex_lock(&(philo->data->fork[last_fork]));
			printf("%ld %d has taken a fork\n", current_time(philo), philo->id);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(&(philo->data->fork[philo->id - 1]));
			if (philo->data->nb_ph == 1)
				ft_wait(time_left(philo) + 1);
		}
	}
	return (0);
}

int	should_end(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mute_stop));
	if (time_left(philo) < 0)
	{
		if (philo->data->stop != INT_MAX)
		{
			philo->data->stop = INT_MAX;
			printf("%ld %d died\n", current_time(philo), philo->id);
		}
		pthread_mutex_unlock(&(philo->data->mute_stop));
		return (1);
	}
	else if (philo->data->stop >= philo->data->nb_ph)
	{
		pthread_mutex_unlock(&(philo->data->mute_stop));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->mute_stop));
	return (0);
}

void	one_more_full(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mute_stop));
	philo->data->stop++;
	pthread_mutex_unlock(&(philo->data->mute_stop));
}
