/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:25 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 09:32:23 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "commontype.h"
#include "utils.h"
#include "philo.h"

void	philo_pick_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo_get_state(philo) == DEAD)
	{
		philo_pick_down_forks(philo);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	if (philo_get_state(philo) == DEAD)
	{
		philo_pick_down_forks(philo);
		return ;
	}
}

void	philo_eat(t_philo *philo, t_int64 tstamp)
{
	pthread_mutex_lock(philo->paper);
	printf("%lld %d is eating\n",
		tstamp - philo->tbegin, philo->idx);
	pthread_mutex_unlock(philo->paper);
	philo_set_teat(philo, tstamp);
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->etime)
			break ;
		if (philo_get_state(philo) == DEAD)
		{
			philo_pick_down_forks(philo);
			return ;
		}
		usleep(100);
	}
	philo_pick_down_forks(philo);
	philo_increase_eat_cnt(philo);
	philo_set_state(philo, SLEEP);
}

void	philo_think(t_philo *philo, t_int64 tstamp)
{
	pthread_mutex_lock(philo->paper);
	printf("%lld %d is thinking\n",
		tstamp - philo->tbegin, philo->idx);
	pthread_mutex_unlock(philo->paper);
	philo_pick_up_forks(philo);
	if (philo_get_state(philo) == DEAD)
		return ;
	pthread_mutex_lock(philo->paper);
	printf("%lld %d has taken a fork\n",
		get_time() - philo->tbegin, philo->idx);
	pthread_mutex_unlock(philo->paper);
	philo_set_state(philo, EAT);
}

void	philo_sleep(t_philo *philo, t_int64 tstamp)
{
	pthread_mutex_lock(philo->paper);
	printf("%lld %d is sleeping\n",
		tstamp - philo->tbegin, philo->idx);
	pthread_mutex_unlock(philo->paper);
	philo->tsleep = tstamp;
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->stime)
			break ;
		if (philo_get_state(philo) == DEAD)
			return ;
		usleep(100);
	}
	philo_set_state(philo, THINK);
}
