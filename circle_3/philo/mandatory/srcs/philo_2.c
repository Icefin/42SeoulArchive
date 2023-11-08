/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:04 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/08 22:36:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "philo.h"

static void	pick_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void philo_process_eat(t_philo *philo)
{
	while (TRUE)
	{

	}

	pick_down_forks(philo);
	philo->state = SLEEP;
}

static t_bool pick_up_forks(t_philo *philo)
{
	
}

static void	philo_process_think(t_philo *philo)
{
	long long current_time;

	current_time = get_current_time_ms();
	if (current_time - philo->eat_start)
	{
		printf("%ld %d is thinking\n", current_time, philo->idx);
		philo->state = DEAD;
		return ;
	}

	if (pick_up_forks(philo) == TRUE)
	{
		philo->eat_start = current_time;
		philo->eat_cnt += 1;
		philo->state = EAT;
	}
	else
	{
		philo->sleep_start = current_time;
		philo->state = SLEEP;
	}
}

static void	philo_process_sleep(t_philo *philo)
{
	while (TRUE)
	{

	}

	philo->state = THINK;
}

void	*philo_start_eating(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->state == EAT)
		philo_process_eat(p);
	else if (p->state == THINK)
		philo_process_think(p);
	else if (p->state == SLEEP)
		philo_process_sleep(p);
}