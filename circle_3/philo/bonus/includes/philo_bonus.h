/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:46:31 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/09 00:54:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>

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
	sem_t			*fork;
}	t_philo;

void	philo_constructor(t_philo *philo);
void	philo_destructor(t_philo *philo);

#endif