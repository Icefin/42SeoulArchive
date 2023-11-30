/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:39 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 09:38:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "chef.h"

void	chef_constructor(t_chef *chef, int argc, char **argv)
{
	int	idx;
	int	nump;
	int	etime;
	int	stime;

	nump = ft_atoi(argv[1]);
	chef->nump = nump;
	chef->dtime = ft_atoi(argv[2]);
	etime = ft_atoi(argv[3]);
	stime = ft_atoi(argv[4]);
	chef->nume = -1;
	if (argc == 6)
		chef->nume = ft_atoi(argv[5]);
	pthread_mutex_init(&(chef->paper), NULL);
	chef->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nump);
	chef->states = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nump);
	chef->philos = (t_philo *)malloc(sizeof(t_philo) * nump);
	idx = -1;
	while (++idx < nump)
	{
		pthread_mutex_init(&(chef->forks[idx]), NULL);
		pthread_mutex_init(&(chef->states[idx]), NULL);
		philo_constructor(&(chef->philos[idx]), idx, etime, stime);
		chef->philos[idx].mtx_state = &(chef->states[idx]);
		chef->philos[idx].paper = &(chef->paper);
		chef->philos[idx].left_fork = &(chef->forks[idx]);
		chef->philos[idx].right_fork = &(chef->forks[(idx + 1) % nump]);
	}
}

void	chef_destructor(t_chef *chef)
{
	int	idx;

	pthread_mutex_destroy(&(chef->paper));
	idx = -1;
	while (++idx < chef->nump)
	{
		philo_destructor(&(chef->philos[idx]));
		pthread_mutex_destroy(&(chef->forks[idx]));
		pthread_mutex_destroy(&(chef->states[idx]));
	}
	free(chef->philos);
	free(chef->forks);
	free(chef->states);
}
