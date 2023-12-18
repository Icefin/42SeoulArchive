/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:31:51 by geshin           ###   ########.fr       */
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
	int		status;

	idx = -1;
	while (++idx < chef->nump)
	{
		pid = serve_idx_philo(&(chef->philos[idx]), get_time());
		chef->pids[idx] = pid;
	}
	idx = 0;
	while (idx < chef->nump)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
			idx++;
		else
		{
			idx = -1;
			while (++idx < chef->nump)
				kill(chef->pids[idx], SIGTERM);
			return ;
		}
	}
}
