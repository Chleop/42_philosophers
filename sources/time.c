/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:51:13 by cproesch          #+#    #+#             */
/*   Updated: 2021/12/01 14:59:44 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (res);
}

int	time_left(t_philo *philo)
{
	return (philo->data->tt_die - (ft_time() - philo->last_meal));
}

void	ft_wait(long x)
{
	long	start;

	start = ft_time();
	while (ft_time() < (start + x))
		usleep(100);
}
