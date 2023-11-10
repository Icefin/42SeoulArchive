/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 21:00:26 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "chef.h"

static void	serve_idx_philo(t_philo *philo, long long tstamp)
{
	philo->begin_stamp = tstamp;
	philo->sleep_stamp = tstamp;
	philo_set_eat_stamp(philo, tstamp);
	pthread_create(&(philo->thread), NULL, philo_start_eating, philo);
}

static t_bool	is_philo_starve(t_philo *philo, long long tstamp, long long time_to_die)
{
	if (tstamp - philo_get_eat_stamp(philo) >= time_to_die)
	{
		philo->dead_stamp = tstamp;
		return (TRUE);
	}
	return (FALSE);
}

void	chef_start_serving(t_chef *chef)
{
	int			idx;
	long long	serve_stamp;

	idx = -1;
	serve_stamp = get_current_time_ms();
	while (++idx < chef->number_of_philo)
		serve_idx_philo(&(chef->philos[idx]), serve_stamp);
}

void	chef_stop_serving(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
		philo_set_state(&(chef->philos[idx]), DEAD);
}

t_bool	chef_check_is_philo_ok(t_chef *chef)
{
	int	idx;
	int	fin;

	idx = -1;
	fin = 0;
	while (++idx < chef->number_of_philo)
	{
		if (is_philo_starve(&(chef->philos[idx]), get_current_time_ms(), chef->time_to_die) == TRUE)
		{
			printf("%lld %d is died\n", chef->philos[idx].dead_stamp - chef->philos[idx].begin_stamp, chef->philos[idx].idx);
			return (FALSE);
		}
		if (philo_get_eat_cnt(&(chef->philos[idx])) >= chef->number_of_times_must_eat)
			fin++;
	}
	if ((chef->number_of_times_must_eat != -1) && (fin == chef->number_of_philo))
		return (FALSE);
	return (TRUE);
}
