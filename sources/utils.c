/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:40:02 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/24 11:01:10 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_non_num(int i, const char *str)
{
	int	j;

	j = 0;
	if (!str[j + i])
		return (-1);
	while (str[j + i])
	{
		if ((str[j + i] < '0') || (str[j + i] > '9'))
			return (-1);
		j++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while ((str[i] == ' ') || ((str[i] >= '\t') && (str[i] <= '\r')))
		i++;
	if (check_non_num(i, str) < 0)
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
		if (nbr > 2147483647)
			return (0);
	}
	return ((int)nbr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
