/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:42:21 by geshin            #+#    #+#             */
/*   Updated: 2023/11/30 09:43:19 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "philo.h"

void	philo_set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(philo->mtx_state);
	if (philo->state == DEAD)
	{
		pthread_mutex_unlock(philo->mtx_state);
		return ;
	}
	philo->state = state;
	pthread_mutex_unlock(philo->mtx_state);
}

void	philo_increase_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_state);
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->mtx_state);
}

void	philo_set_teat(t_philo *philo, t_int64 stamp)
{
	pthread_mutex_lock(philo->mtx_state);
	philo->teat = stamp;
	pthread_mutex_unlock(philo->mtx_state);
}
