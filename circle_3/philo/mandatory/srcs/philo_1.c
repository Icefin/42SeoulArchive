/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/09 00:06:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_constructor(t_philo *philo, int idx, pthread_mutex_t *left, pthread_mutex_t *right)
{
	philo->idx = (idx + 1);
	philo->state = THINK;
	if ((philo->idx % 2) == 0)
		philo->state = SLEEP;
	philo->eat_cnt = 0;
	philo->left_fork = left;
	philo->right_fork = right;
}

#include <stdio.h>
void	philo_destructor(t_philo *philo)
{
	printf("Joining %d Philo\n", philo->idx);
	pthread_join(philo->thread, NULL);
}