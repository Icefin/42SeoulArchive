/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:46:31 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/12 02:22:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include "commontype_bonus.h"

typedef enum e_state
{
	EAT,
	THINK,
	SLEEP,
	DEAD
}	t_state;

typedef struct s_philo
{
	int			idx;
	t_state		state;
	int			eat_cnt;
	t_int64		eat_stamp;
	t_int64		sleep_stamp;
	t_int64		begin_stamp;
	t_int64		dead_stamp;

	int			time_to_eat;
	int			time_to_sleep;

	pthread_t	thread;
	sem_t		*smp;
	sem_t		*fork;
}	t_philo;

void	philo_constructor(t_philo *philo, int idx, int time_to_eat, int time_to_sleep);
void	philo_destructor(t_philo *philo);

void	philo_pick_up_forks(t_philo *philo);
void	philo_pick_down_forks(t_philo *philo);
void	*philo_start_eating(void *philo);

t_state	philo_get_state(t_philo *philo);
void	philo_set_state(t_philo *philo, t_state state);
int		philo_get_eat_cnt(t_philo *philo);
void	philo_increase_eat_cnt(t_philo *philo);
t_int64	philo_get_eat_stamp(t_philo *philo);
void	philo_set_eat_stamp(t_philo *philo, t_int64 stamp);

#endif