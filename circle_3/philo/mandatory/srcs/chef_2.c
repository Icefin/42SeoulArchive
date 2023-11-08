/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/08 23:21:01 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "chef.h"

static void	serve_idx_philo(t_philo *philo)
{
	pthread_create(&(philo->thread), NULL, philo_start_eating, philo);
}

void	chef_start_serving(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
		serve_idx_philo(&(chef->philos[idx]));
}

t_bool	chef_check_is_philo_ok(t_chef* chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
	{
		if (chef->philos[idx].state == DEAD)
			return (FALSE);
	}
	return (TRUE);
}
