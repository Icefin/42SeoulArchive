/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:45:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/15 15:41:24 by singeonho        ###   ########.fr       */
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
	sem_wait(philo->fork);
}

void	philo_eat(t_philo *philo, t_int64 tstamp)
{
	sem_wait(philo->smp);
	printf("%lld %d is eating\n",
		tstamp - philo->begin_stamp, philo->idx);
	philo->eat_stamp = tstamp;
	sem_post(philo->smp);
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->time_to_eat)
			break ;
		usleep(100);
	}
	philo_pick_down_forks(philo);
	philo->eat_cnt++;
	philo->state = SLEEP;
}

void	philo_think(t_philo *philo, t_int64 tstamp)
{
	sem_wait(philo->smp);
	printf("%lld %d is thinking\n",
		tstamp - philo->begin_stamp, philo->idx);
	sem_post(philo->smp);
	philo_pick_up_forks(philo);
	sem_wait(philo->smp);
	printf("%lld %d has taken a fork\n",
		get_time() - philo->begin_stamp, philo->idx);
	sem_post(philo->smp);
	philo->state = EAT;
}

void	philo_sleep(t_philo *philo, t_int64 tstamp)
{
	sem_wait(philo->smp);
	printf("%lld %d is sleeping\n",
		tstamp - philo->begin_stamp, philo->idx);
	sem_post(philo->smp);
	philo->sleep_stamp = tstamp;
	while (TRUE)
	{
		if (get_time() - tstamp >= philo->time_to_sleep)
			break ;
		usleep(100);
	}
	philo->state = THINK;
}
