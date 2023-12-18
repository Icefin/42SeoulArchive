/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:35:57 by geshin           ###   ########.fr       */
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

static char	*generate_unique_name(t_philo *philo)
{
	char	*prefix;
	char	*num;
	char	*res;

	prefix = "bin_sem";
	num = ft_itoa(philo->idx);
	res = ft_strjoin(prefix, num);
	return (res);
}

static sem_t	*generate_binary_semaphore(t_philo *philo)
{
	char	*name;
	sem_t	*bin;

	name = generate_unique_name(philo);
	sem_unlink(name);
	bin = sem_open(name, O_CREAT, 0644, 1);
	free(name);
	return (bin);
}

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
	p->smp = generate_binary_semaphore(p);
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
		if (p->nume != -1 && p->eat_cnt >= p->nume)
		{
			philo_pick_down_forks(philo);
			sem_close(p->smp);
			exit(0);
		}
		usleep(100);
	}
}
