/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/15 16:02:35 by singeonho        ###   ########.fr       */
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
	t_int64	stamp;
	t_philo	*p;

	p = (t_philo *)philo;
	while (TRUE)
	{
		sem_wait(p->smp);
		stamp = p->eat_stamp;
		sem_post(p->smp);
		if (get_time() - stamp >= p->time_to_die)
		{
			sem_wait(p->smp);
			printf("%lld %d died\n",
				get_time() - p->begin_stamp, p->idx);
			sem_post(p->smp);
			philo_pick_down_forks(philo);
			sem_close(p->smp);
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
	sem_unlink("smp");
	p->smp = sem_open("smp", O_CREAT, 0644, 1);
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

		if (p->number_of_times_must_eat != -1 && p->eat_cnt >= p->number_of_times_must_eat)
		{
			philo_pick_down_forks(philo);
			sem_close(p->smp);
			exit(0);
		}
		usleep(100);
	}
	sem_close(p->smp);
	exit(1);
}
