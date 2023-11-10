/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:57:42 by geshin            #+#    #+#             */
/*   Updated: 2023/11/10 21:01:46 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long	philo_get_eat_stamp(t_philo *philo)
{
	long long	eat_stamp;

	pthread_mutex_lock(philo->mtx);
	eat_stamp = philo->eat_stamp;
	pthread_mutex_unlock(philo->mtx);
	return (eat_stamp);
}

void	philo_set_eat_stamp(t_philo *philo, long long stamp)
{
	pthread_mutex_lock(philo->mtx);
	philo->eat_stamp = stamp;
	pthread_mutex_unlock(philo->mtx);
}
