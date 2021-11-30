/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:36 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/25 16:58:09 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_ph)
	{
		if (pthread_mutex_destroy(&(data->fork[i])))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_data **data)
{
	if (*data)
	{
		if ((*data)->philo)
		{
			free ((*data)->philo);
			(*data)->philo = NULL;
		}
		if ((*data)->fork)
		{
			free ((*data)->fork);
			(*data)->fork = NULL;
		}
		free ((*data));
		(*data) = NULL;
	}
	return ;
}
