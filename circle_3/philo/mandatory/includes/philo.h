/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:05:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/08 23:32:13 by singeonho        ###   ########.fr       */
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

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

void	philo_constructor(t_philo *philo, int idx, pthread_mutex_t *left, pthread_mutex_t *right);
void	philo_destructor(t_philo *philo);

void	*philo_start_eating(void *input);

#endif