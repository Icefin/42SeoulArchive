/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:05:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 09:37:50 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "commontype.h"

typedef enum e_state
{
	EAT,
	THINK,
	SLEEP,
	DEAD
}	t_state;

typedef struct s_philo
{
	int				idx;
	t_state			state;
	int				eat_cnt;
	t_int64			teat;
	t_int64			tsleep;
	t_int64			tbegin;
	t_int64			tdead;

	int				etime;
	int				stime;

	pthread_t		thread;
	pthread_mutex_t	*paper;
	pthread_mutex_t	*mtx_state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

void	philo_constructor(t_philo *philo, int idx, int etime, int stime);
void	philo_destructor(t_philo *philo);

void	philo_pick_up_forks(t_philo *philo);
void	philo_pick_down_forks(t_philo *philo);
void	*philo_start_eating(void *philo);

t_state	philo_get_state(t_philo *philo);
void	philo_set_state(t_philo *philo, t_state state);
int		philo_get_eat_cnt(t_philo *philo);
void	philo_increase_eat_cnt(t_philo *philo);
t_int64	philo_get_teat(t_philo *philo);
void	philo_set_teat(t_philo *philo, t_int64 stamp);

#endif