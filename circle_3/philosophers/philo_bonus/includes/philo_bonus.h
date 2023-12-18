/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:46:31 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:34:08 by geshin           ###   ########.fr       */
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

	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			nume;

	pthread_t	thread;
	sem_t		*smp;
	sem_t		*fork;
}	t_philo;

void	philo_constructor(t_philo *philo, int idx, int etime, int stime);

void	philo_pick_up_forks(t_philo *philo);
void	philo_pick_down_forks(t_philo *philo);
void	*philo_start_eating(void *philo);

#endif