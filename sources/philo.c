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

void	some_must_think_first(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		printf("%ld %d is thinking\n", current_time(philo), philo->id);
		ft_wait(philo->data->tt_eat);
	}
	else if ((philo->data->nb_ph != 1) && (philo->id == philo->data->nb_ph))
	{
		printf("%ld %d is thinking\n", current_time(philo), philo->id);
		if ((time_left(philo) >= (2 * philo->data->tt_eat))
			&& (!should_end(philo)))
			ft_wait(2 *(philo->data->tt_eat));
		else if (!should_end(philo))
			ft_wait(time_left(philo) + 1);
	}
}

void	*f(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	some_must_think_first(philo);
	while (!should_end(philo))
	{
		if (!lock_both_forks(philo))
			break ;
		ft_eat(philo);
		unlock_both_forks(philo);
		if (should_end(philo))
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	should_end(philo);
	return (NULL);
}

int	create_philos(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_ph)
	{
		d->philo[i].id = i + 1;
		d->philo[i].nb_meals = 0;
		d->philo[i].last_meal = d->start_time;
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
