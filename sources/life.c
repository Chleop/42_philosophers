/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:22:03 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/24 12:07:08 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_right_fork(t_philo *philo)
{
	if (philo->id == 1)
		pthread_mutex_lock(&(philo->data->fork[philo->data->nb_ph - 1]));
	else
		pthread_mutex_lock(&(philo->data->fork[philo->id - 2]));
}

void	unlock_both_forks(t_philo *philo)
{
	if (philo->id == 1)
		pthread_mutex_unlock(&(philo->data->fork[philo->data->nb_ph - 1]));
	else
		pthread_mutex_unlock(&(philo->data->fork[philo->id - 2]));
	pthread_mutex_unlock(&(philo->data->fork[philo->id - 1]));
}

void	check_death(t_philo *philo)
{
	long	to_death;

	if (!philo->data->stop)
	{
		philo->data->stop = 1;
		to_death = ft_time();
		usleep(100);
		printf("%ld %d died\n", to_death, philo->id);
	}
	return ;
}

void	*f(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while ((ft_time() - philo->last_meal) <= philo->data->tt_die)
	{
		if (philo->id % 2 == 0)
         	usleep(1);
		lock_right_fork(philo);
		if (((philo->data->nb_ph != 1) && (pthread_mutex_lock(&(philo->data->fork[philo->id - 1])) == 0))
			&& (!philo->data->stop))
		{
			ft_eat(philo);
			unlock_both_forks(philo);
			if (((ft_time() - philo->last_meal) > philo->data->tt_die) || (philo->data->stop))
				break;
			if (philo->data->count_full >= philo->data->nb_ph)
				return (NULL);
			ft_sleep(philo);
			ft_think(philo);
		}
		else if (philo->data->nb_ph == 1)
			pthread_mutex_unlock(&(philo->data->fork[0]));
		else
			pthread_mutex_unlock(&(philo->data->fork[philo->id - 2]));
	}
	check_death(philo);
	return (NULL);
}

int	animate_phs(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_ph)
	{
		d->philo[i].id = i + 1;
		d->philo[i].nb_meals = 0;
		d->philo[i].last_meal = ft_time();
		d->philo[i].data = d;
		if (pthread_create(&(d->philo[i].th), NULL, &f, (void *)&(d->philo[i])))
			return (0);
		i++;
	}
	i = 0;
	while (i < d->nb_ph)
	{
		if (pthread_join(d->philo[i].th, NULL))
			return (0);
		i++;
	}
	return (1);
}
