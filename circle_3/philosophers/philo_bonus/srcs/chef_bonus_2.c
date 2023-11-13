/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/13 20:40:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include "utils_bonus.h"
#include "chef_bonus.h"

static pid_t	serve_idx_philo(t_philo *philo, t_int64 tstamp)
{
	pid_t	pid;

	philo->begin_stamp = tstamp;
	philo->sleep_stamp = tstamp;
	philo->eat_stamp = tstamp;
	pid = fork();
	if (pid == 0)
		philo_start_eating(philo);
	return (pid);
}

void	chef_start_serving(t_chef *chef)
{
	pid_t	pid;
	int		idx;
	t_int64	tserve;

	idx = -1;
	tserve = get_time();
	while (++idx < chef->number_of_philo)
	{
		pid = serve_idx_philo(&(chef->philos[idx]), tserve);
		chef->pids[idx] = pid;
	}
	waitpid(0, NULL, 0);
	idx = -1;
	while (++idx < chef->number_of_philo)
		kill(chef->pids[idx], SIGTERM);
}
