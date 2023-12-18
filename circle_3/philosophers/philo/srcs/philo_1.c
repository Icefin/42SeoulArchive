/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:25:27 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chef.h"
#include "philo.h"

void	philo_constructor(t_philo *philo, int idx, t_chef *chef)
{
	philo->idx = (idx + 1);
	philo->state = THINK;
	if ((philo->idx % 2) == 0)
		philo->state = SLEEP;
	philo->eat_cnt = 0;
	philo->etime = chef->etime;
	philo->stime = chef->stime;
	philo->mtx_state = &(chef->states[idx]);
	philo->paper = &(chef->paper);
	philo->left_fork = &(chef->forks[idx]);
	philo->right_fork = &(chef->forks[(idx + 1) % chef->nump]);
}

void	philo_destructor(t_philo *philo)
{
	pthread_join(philo->thread, NULL);
}
