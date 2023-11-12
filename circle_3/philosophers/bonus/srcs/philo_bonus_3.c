/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:45:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/12 16:34:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "utils_bonus.h"
#include "philo_bonus.h"

void	philo_pick_down_forks(t_philo *philo)
{
	sem_post(philo->fork);
	sem_post(philo->fork);
}

void	philo_pick_up_forks(t_philo *philo)
{
	sem_wait(philo->fork);
	if (philo_get_state(philo) == DEAD)
	{
		philo_pick_down_forks(philo);
		return ;
	}
	sem_wait(philo->fork);
	if (philo_get_state(philo) == DEAD)
	{
		philo_pick_down_forks(philo);
		return ;
	}
}

void	philo_eat(t_philo *philo, t_int64 tstamp)
{
	printf("%lld %d is eating\n",
	 tstamp - philo->begin_stamp, philo->idx);
	philo_set_eat_stamp(philo, tstamp);
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->time_to_eat)
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
	printf("%lld %d is thinking\n",
	 tstamp - philo->begin_stamp, philo->idx);
	philo_pick_up_forks(philo);
	if (philo_get_state(philo) == DEAD)
		return ;
	printf("%lld %d has taken a fork\n",
	 get_time() - philo->begin_stamp, philo->idx);
	philo_set_state(philo, EAT);
}

void	philo_sleep(t_philo *philo, t_int64 tstamp)
{
	printf("%lld %d is sleeping\n",
	 tstamp - philo->begin_stamp, philo->idx);
	philo->sleep_stamp = tstamp;
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->time_to_sleep)
			break ;
		if (philo_get_state(philo) == DEAD)
			return ;
		usleep(100);
	}
	philo_set_state(philo, THINK);
}
