/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:57:42 by geshin            #+#    #+#             */
/*   Updated: 2023/11/11 01:33:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "philo.h"

t_state	philo_get_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(philo->mtx);
	state = philo->state;
	pthread_mutex_unlock(philo->mtx);
	return (state);
}

void	philo_set_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(philo->mtx);
	if (philo->state == DEAD)
	{
		pthread_mutex_unlock(philo->mtx);
		return ;
	}
	philo->state = state;
	pthread_mutex_unlock(philo->mtx);
}

int	philo_get_eat_cnt(t_philo *philo)
{
	int	eat_cnt;

	pthread_mutex_lock(philo->mtx);
	eat_cnt = philo->eat_cnt;
	pthread_mutex_unlock(philo->mtx);
	return (eat_cnt);
}

void	philo_increase_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx);
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->mtx);
}

t_int64	philo_get_teat(t_philo *philo)
{
	t_int64	teat;

	pthread_mutex_lock(philo->mtx);
	teat = philo->teat;
	pthread_mutex_unlock(philo->mtx);
	return (teat);
}

void	philo_set_teat(t_philo *philo, t_int64 stamp)
{
	pthread_mutex_lock(philo->mtx);
	philo->teat = stamp;
	pthread_mutex_unlock(philo->mtx);
}
