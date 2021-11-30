/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:35:10 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/29 17:40:43 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if ((argc < 5) || (argc > 6))
	{
		ft_putstr("Error: Must give 4 or 5 arguments\n");
		return (1);
	}
	data = malloc (sizeof(t_data) * 1);
	if ((!data) || (!initialize_data(argv, data)) || (!initialize_mutex(data))
		|| (!animate_phs(data)) || (!destroy_mutex(data)))
	{
		ft_putstr("Error\n");
		ft_free(&data);
		return (1);
	}
	ft_free(&data);
	return (0);
}
