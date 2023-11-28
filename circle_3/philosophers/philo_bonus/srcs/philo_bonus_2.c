/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 08:07:27 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "utils_bonus.h"
#include "philo_bonus.h"

extern void	philo_eat(t_philo *philo, t_int64 tstamp);
extern void	philo_think(t_philo *philo, t_int64 tstamp);
extern void	philo_sleep(t_philo *philo, t_int64 tstamp);

void	*philo_coroutine_starve(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (TRUE)
	{
		if (get_time() - p->eat_stamp >= p->time_to_die)
		{
			printf("%lld %d is died\n",
				get_time() - p->begin_stamp, p->idx);
			philo_pick_down_forks(philo);
			exit(1);
		}
		if (p->number_of_times_must_eat != -1 && p->eat_cnt >= p->number_of_times_must_eat)
		{
			philo_pick_down_forks(philo);
			exit(1);
		}
		usleep(100);
	}
}

void	*philo_start_eating(void *philo)
{
	t_philo		*p;
	pthread_t	tid;
	t_int64		tstamp;

	p = (t_philo *)philo;
	pthread_create(&tid, NULL, philo_coroutine_starve, philo);
	while (TRUE)
	{
		tstamp = get_time();
		if (p->state == EAT)
			philo_eat(p, tstamp);
		else if (p->state == THINK)
			philo_think(p, tstamp);
		else if (p->state == SLEEP)
			philo_sleep(p, tstamp);
		usleep(100);
	}
	exit(1);
}
