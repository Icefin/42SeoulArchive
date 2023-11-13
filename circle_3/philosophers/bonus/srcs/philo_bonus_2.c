/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/13 20:02:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils_bonus.h"
#include "philo_bonus.h"

extern void	philo_eat(t_philo *philo, t_int64 tstamp);
extern void	philo_think(t_philo *philo, t_int64 tstamp);
extern void	philo_sleep(t_philo *philo, t_int64 tstamp);

void	*philo_start_eating(void *philo)
{
	t_philo		*p;
	t_int64		tstamp;

	p = (t_philo *)philo;
	while (TRUE)
	{
		tstamp = get_time();
		if (p->state == EAT)
			philo_eat(p, tstamp);
		else if (p->state == THINK)
			philo_think(p, tstamp);
		else if (p->state == SLEEP)
			philo_sleep(p, tstamp);

		if (p->state == DEAD)
			break ;
		usleep(100);
	}
	exit(0);
}
