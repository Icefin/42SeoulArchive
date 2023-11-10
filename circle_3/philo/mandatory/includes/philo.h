/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:05:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 21:11:52 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

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
	long long		eat_stamp;
	long long		sleep_stamp;
	long long		begin_stamp;
	long long		dead_stamp;

	int				time_to_eat;
	int				time_to_sleep;

	pthread_t		thread;
	pthread_mutex_t	*mtx;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

void		philo_constructor(t_philo *philo, int idx, pthread_mutex_t *left, pthread_mutex_t *right);
void		philo_destructor(t_philo *philo);

void		philo_pick_up_forks(t_philo *philo);
void		philo_pick_down_forks(t_philo *philo);
void		*philo_start_eating(void *input);

t_state		philo_get_state(t_philo *philo);
void		philo_set_state(t_philo *philo, t_state state);
int			philo_get_eat_cnt(t_philo *philo);
void		philo_increase_eat_cnt(t_philo *philo);
long long	philo_get_eat_stamp(t_philo *philo);
void		philo_set_eat_stamp(t_philo *philo, long long stamp);

#endif