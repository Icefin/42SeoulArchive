/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:25 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 17:36:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "commontype.h"
#include "utils.h"
#include "philo.h"

extern t_bool	is_philo_starve(t_philo *philo, long long tstamp);

static void	pick_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_philo_starve(philo, get_current_time_ms()) == TRUE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(philo->mtx);
		if (philo->state == END)
		{
			pthread_mutex_unlock(philo->mtx);
			return ;
		}
		philo->state = DEAD;
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	if (is_philo_starve(philo, get_current_time_ms()) == TRUE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->mtx);
		if (philo->state == END)
		{
			pthread_mutex_unlock(philo->mtx);
			return ;
		}
		philo->state = DEAD;
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
}

void	philo_eat(t_philo *philo, long long tstamp)
{
	printf("%lld %d is eating\n", tstamp - philo->begin_stamp, philo->idx);
	philo->eat_stamp = tstamp;
	while (TRUE)
	{
		if (get_current_time_ms() - tstamp >= philo->time_to_eat)
			break ;
		pthread_mutex_lock(philo->mtx);
		if (philo->state == END)
		{
			pthread_mutex_unlock(philo->mtx);
			pick_down_forks(philo);
			return ;
		}
		pthread_mutex_unlock(philo->mtx);
		usleep(500);
	}
	pick_down_forks(philo);
	pthread_mutex_lock(philo->mtx);
	if (philo->state == END)
	{
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	philo->eat_cnt++;
	philo->state = SLEEP;
	pthread_mutex_unlock(philo->mtx);
}

void	philo_think(t_philo *philo, long long tstamp)
{
	printf("%lld %d is thinking\n", tstamp - philo->begin_stamp, philo->idx);
	pick_up_forks(philo);
	pthread_mutex_lock(philo->mtx);
	if (philo->state == DEAD || philo->state == END)
	{
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	pthread_mutex_unlock(philo->mtx);
	printf("%lld %d has taken a fork\n", get_current_time_ms() - philo->begin_stamp, philo->idx);
	pthread_mutex_lock(philo->mtx);
	if (philo->state == END)
	{
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	philo->state = EAT;
	pthread_mutex_unlock(philo->mtx);
}

void	philo_sleep(t_philo *philo, long long tstamp)
{
	printf("%lld %d is sleeping\n", tstamp - philo->begin_stamp, philo->idx);

	philo->sleep_stamp = tstamp;
	while (TRUE)
	{
		if (get_current_time_ms() - tstamp >= philo->time_to_sleep)
			break ;
		if (is_philo_starve(philo, get_current_time_ms()) == TRUE)
		{
			pthread_mutex_lock(philo->mtx);
			if (philo->state == END)
			{
				pthread_mutex_unlock(philo->mtx);
				return ;
			}
			philo->state = DEAD;
			pthread_mutex_unlock(philo->mtx);
			return ;
		}
		usleep(500);
	}
	pthread_mutex_lock(philo->mtx);
	if (philo->state == END)
	{
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	philo->state = THINK;
	pthread_mutex_unlock(philo->mtx);
}
