/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/11 01:45:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "chef.h"

static void	serve_idx_philo(t_philo *philo, t_int64 tstamp)
{
	philo->tbegin = tstamp;
	philo->tsleep = tstamp;
	philo_set_teat(philo, tstamp);
	pthread_create(&(philo->thread), NULL, philo_start_eating, philo);
}

static t_bool	is_starve(t_philo *philo, t_int64 tstamp, t_int64 dtime)
{
	if (tstamp - philo_get_teat(philo) >= dtime)
	{
		philo->tdead = tstamp;
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
	while (++idx < chef->nump)
		serve_idx_philo(&(chef->philos[idx]), tserve);
}

void	chef_stop_serving(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->nump)
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
	while (++idx < chef->nump)
	{
		if (is_starve(&(chef->philos[idx]), get_time(), chef->dtime) == TRUE)
		{
			philo_set_state(&(chef->philos[idx]), DEAD);
			printf("%lld %d is died\n",
			 chef->philos[idx].tdead - chef->philos[idx].tbegin, idx + 1);
			return (FALSE);
		}
		if (philo_get_eat_cnt(&(chef->philos[idx])) >= chef->nump)
			fin++;
	}
	if ((chef->nume != -1) && (fin == chef->nump))
		return (FALSE);
	return (TRUE);
}
