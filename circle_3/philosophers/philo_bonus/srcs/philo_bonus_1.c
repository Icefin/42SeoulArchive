/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:32:52 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo_bonus.h"

void	philo_constructor(t_philo *philo, int idx, int etime, int stime)
{
	philo->idx = (idx + 1);
	philo->state = THINK;
	if ((philo->idx % 2) == 0)
		philo->state = SLEEP;
	philo->eat_cnt = 0;
	philo->time_to_eat = etime;
	philo->time_to_sleep = stime;
}
