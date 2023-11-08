/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:04 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/09 00:00:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "utils.h"
#include "philo.h"

static void	pick_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
}

void	*philo_start_eating(void *philo)
{
	t_philo		*p;
	long long	time_stamp;

	p = (t_philo *)philo;
	p->eat_stamp = 0;
	p->sleep_stamp = 0;
	p->begin_stamp = get_current_time_ms();
	while (TRUE)
	{
		time_stamp = get_current_time_ms() - p->begin_stamp;
		if (time_stamp - p->eat_stamp >= p->time_to_die)
		{
			printf("%lld %d is died\n", time_stamp, p->idx);
			p->state = DEAD;
			break ;
		}

		if (p->state == EAT)
		{
			printf("%lld %d is eating\n", time_stamp, p->idx);
			p->eat_stamp = time_stamp;
			while (TRUE)
			{
				if (get_current_time_ms() - time_stamp - p->begin_stamp >= p->time_to_eat)
					break ;
				usleep(500);
			}
			pick_down_forks(p);
			p->state = SLEEP;
		}
		else if (p->state == THINK)
		{
			printf("%lld %d is thinking\n", time_stamp, p->idx);
			pick_up_forks(p);
			printf("%lld %d has taken a fork\n", get_current_time_ms() - p->begin_stamp, p->idx);
			p->state = EAT;
		}
		else if (p->state == SLEEP)
		{
			printf("%lld %d is sleeping\n", time_stamp, p->idx);
			p->sleep_stamp = time_stamp;
			while (TRUE)
			{
				if (get_current_time_ms() - time_stamp - p->begin_stamp >= p->time_to_sleep)
					break ;
				if (get_current_time_ms() - p->eat_stamp - p->begin_stamp >= p->time_to_die)
					break ;
				usleep(500);
			}
			p->state = THINK;
		}
	}
	return (0);
}
