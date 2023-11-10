/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 17:39:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "chef.h"

static void	serve_idx_philo(t_philo *philo, long long tstamp)
{
	philo->begin_stamp = tstamp;
	pthread_create(&(philo->thread), NULL, philo_start_eating, philo);
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
	{
		pthread_mutex_lock(&(chef->states[idx]));
		chef->philos[idx].state = END;
		pthread_mutex_unlock(&(chef->states[idx]));
	}
}

t_bool	chef_check_is_philo_ok(t_chef* chef)
{
	int	idx;
	int	eat_fin_num;

	idx = -1;
	eat_fin_num = 0;
	while (++idx < chef->number_of_philo)
	{
		pthread_mutex_lock(&(chef->states[idx]));
		if (chef->philos[idx].state == DEAD)
		{
			pthread_mutex_unlock(&(chef->states[idx]));
			return (FALSE);
		}
		if (chef->philos[idx].eat_cnt >= chef->number_of_times_must_eat)
			eat_fin_num++;
		pthread_mutex_unlock(&(chef->states[idx]));
	}
	if ((chef->number_of_times_must_eat != -1) && (eat_fin_num == chef->number_of_philo))
		return (FALSE);
	return (TRUE);
}