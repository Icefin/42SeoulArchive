/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:57:42 by geshin            #+#    #+#             */
/*   Updated: 2023/11/30 09:42:57 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "philo.h"

t_state	philo_get_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(philo->mtx_state);
	state = philo->state;
	pthread_mutex_unlock(philo->mtx_state);
	return (state);
}

int	philo_get_eat_cnt(t_philo *philo)
{
	int	eat_cnt;

	pthread_mutex_lock(philo->mtx_state);
	eat_cnt = philo->eat_cnt;
	pthread_mutex_unlock(philo->mtx_state);
	return (eat_cnt);
}

t_int64	philo_get_teat(t_philo *philo)
{
	t_int64	teat;

	pthread_mutex_lock(philo->mtx_state);
	teat = philo->teat;
	pthread_mutex_unlock(philo->mtx_state);
	return (teat);
}
