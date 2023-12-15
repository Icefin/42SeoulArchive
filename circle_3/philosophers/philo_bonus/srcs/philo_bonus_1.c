/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/15 15:18:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo_bonus.h"

void	philo_constructor(t_philo *philo, int idx, int time_to_eat, int time_to_sleep)
{
	philo->idx = (idx + 1);
	philo->state = THINK;
	if ((philo->idx % 2) == 0)
		philo->state = SLEEP;
	philo->eat_cnt = 0;
	philo->time_to_eat = time_to_eat;
	philo->time_to_sleep = time_to_sleep;
}
