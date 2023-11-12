/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/12 16:32:32 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils_bonus.h"
#include "chef_bonus.h"

static void	serve_idx_philo(t_philo *philo, t_int64 tstamp)
{
	philo->begin_stamp = tstamp;
	philo->sleep_stamp = tstamp;
	philo_set_eat_stamp(philo, tstamp);
	//pthread_create(&(philo->thread), NULL, philo_start_eating, philo);
}

static t_bool	is_starve(t_philo *philo, t_int64 tstamp, t_int64 dtime)
{
	if (tstamp - philo_get_eat_stamp(philo) >= dtime)
	{
		philo->dead_stamp = tstamp;
		return (TRUE);
	}
	return (FALSE);
}

void	chef_start_serving(t_chef *chef)
{
	int		idx;
	t_int64	tserve;

	idx = -1;
	tserve = get_time();
	while (++idx < chef->number_of_philo)
		serve_idx_philo(&(chef->philos[idx]), tserve);
}

void	chef_stop_serving(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
	{
		philo_set_state(&(chef->philos[idx]), DEAD);
		philo_pick_down_forks(&(chef->philos[idx]));
	}
}

t_bool	chef_check_is_philo_ok(t_chef *chef)
{
	int	idx;
	int	fin;

	idx = -1;
	fin = 0;
	while (++idx < chef->number_of_philo)
	{
		if (is_starve(&(chef->philos[idx]), get_time(), chef->time_to_die) == TRUE)
		{
			philo_set_state(&(chef->philos[idx]), DEAD);
			printf("%lld %d is died\n",
			 chef->philos[idx].dead_stamp - chef->philos[idx].begin_stamp, idx + 1);
			return (FALSE);
		}
		if (philo_get_eat_cnt(&(chef->philos[idx])) >= chef->number_of_philo)
			fin++;
	}
	if ((chef->number_of_times_must_eat != -1) && (fin == chef->number_of_philo))
		return (FALSE);
	return (TRUE);
}
