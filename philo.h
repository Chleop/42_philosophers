/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   ph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:35:38 by cproesch          #+#    #+#             */
/*   Updated: 2021/11/24 11:48:37 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ph_H
# define ph_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_philo;

typedef struct s_data
{
	int				nb_ph;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	pthread_mutex_t *fork;
	struct s_philo	*philo;
	int				tt_think;
	int				max_meals;
	int				count_full;
	int				stop;
}   t_data;

typedef struct  s_philo
{
	int			id;
	pthread_t	th;
	t_data		*data;
	long		last_meal;
	int			nb_meals;
}   t_philo;

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
int		initialize_data(char **argv, t_data *data);
int		initialize_mutex(t_data *data);
int		animate_phs(t_data *data);
int		destroy_mutex(t_data *data);
void	ft_free(t_data **data);
long	ft_time(void);
int		time_left(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

#endif