/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/11 01:31:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_constructor(t_philo *philo, int idx, int etime, int stime)
{
	philo->idx = (idx + 1);
	philo->state = THINK;
	if ((philo->idx % 2) == 0)
		philo->state = SLEEP;
	philo->eat_cnt = 0;
	philo->etime = etime;
	philo->stime = stime;
}

void	philo_destructor(t_philo *philo)
{
	pthread_join(philo->thread, NULL);
}
