/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:04 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 21:01:05 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "commontype.h"
#include "utils.h"
#include "philo.h"

extern void	philo_eat(t_philo *philo, long long tstamp);
extern void	philo_think(t_philo *philo, long long tstamp);
extern void	philo_sleep(t_philo *philo, long long tstamp);

void	*philo_start_eating(void *philo)
{
	t_philo		*p;
	long long	tstamp;

	p = (t_philo *)philo;
	while (TRUE)
	{
		tstamp = get_current_time_ms();
		if (philo_get_state(p) == EAT)
			philo_eat(p, tstamp);
		else if (philo_get_state(p) == THINK)
			philo_think(p, tstamp);
		else if (philo_get_state(p) == SLEEP)
			philo_sleep(p, tstamp);
		if (philo_get_state(p) == DEAD)
			break ;
		usleep(100);
	}
	return (0);
}
