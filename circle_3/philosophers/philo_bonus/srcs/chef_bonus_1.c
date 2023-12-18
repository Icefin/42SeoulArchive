/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:34:19 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "chef_bonus.h"
#include "utils_bonus.h"

void	chef_constructor(t_chef *chef, int argc, char **argv)
{
	int	idx;
	int	dtime;
	int	etime;
	int	stime;
	int	nume;

	chef->nump = ft_atoi(argv[1]);
	dtime = ft_atoi(argv[2]);
	etime = ft_atoi(argv[3]);
	stime = ft_atoi(argv[4]);
	nume = -1;
	if (argc == 6)
		nume = ft_atoi(argv[5]);
	sem_unlink("forks");
	chef->forks = sem_open("forks", O_CREAT, 0644, chef->nump);
	chef->pids = (pid_t *)malloc(sizeof(pid_t) * chef->nump);
	chef->philos = (t_philo *)malloc(sizeof(t_philo) * chef->nump);
	idx = -1;
	while (++idx < chef->nump)
	{
		philo_constructor(&(chef->philos[idx]), idx, etime, stime);
		chef->philos[idx].time_to_die = dtime;
		chef->philos[idx].nume = nume;
		chef->philos[idx].fork = chef->forks;
	}
}

void	chef_destructor(t_chef *chef)
{
	int	idx;

	idx = -1;
	free(chef->pids);
	free(chef->philos);
	sem_unlink("forks");
	sem_close(chef->forks);
}
