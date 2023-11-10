/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:04 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 17:34:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "commontype.h"
#include "utils.h"
#include "philo.h"

extern void	philo_eat(t_philo *philo, long long tstamp);
extern void philo_think(t_philo *philo, long long tstamp);
extern void	philo_sleep(t_philo *philo, long long tstamp);

t_bool	is_philo_starve(t_philo *philo, long long tstamp)
{
	if (tstamp - philo->eat_stamp >= philo->time_to_die)
		return (TRUE);
	return (FALSE);
}

void	*philo_start_eating(void *philo)
{
	t_philo		*p;
	long long	tstamp;

	p = (t_philo *)philo;
	p->eat_stamp = p->begin_stamp;
	p->sleep_stamp = p->begin_stamp;
	while (TRUE)
	{
		pthread_mutex_lock(p->mtx);
		if (p->state == END)
		{
			pthread_mutex_unlock(p->mtx);
			break ;
		}
		tstamp = get_current_time_ms();
		if (p->state == DEAD || is_philo_starve(p, tstamp) == TRUE)
		{
			printf("%lld %d is died\n", tstamp - p->begin_stamp, p->idx);
			p->state = DEAD;
			pthread_mutex_unlock(p->mtx);
			break ;
		}
		pthread_mutex_unlock(p->mtx);

		if (p->state == EAT)
			philo_eat(p, tstamp);
		else if (p->state == THINK)
			philo_think(p, tstamp);
		else if (p->state == SLEEP)
			philo_sleep(p, tstamp);
		usleep(500);
	}
	return (0);
}
