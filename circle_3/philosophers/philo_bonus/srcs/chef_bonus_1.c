/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/13 19:57:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "chef_bonus.h"
#include "utils_bonus.h"

void	chef_constructor(t_chef *chef, int argc, char **argv)
{
	int	idx;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	chef->number_of_philo = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	chef->number_of_times_must_eat = -1;
	if (argc == 6)
		chef->number_of_times_must_eat = ft_atoi(argv[5]);
	chef->forks = sem_open("forks", O_CREAT, 0644, chef->number_of_philo);
	chef->pids = (pid_t *)malloc(sizeof(pid_t) * chef->number_of_philo);
	chef->philos = (t_philo *)malloc(sizeof(t_philo) * chef->number_of_philo);
	idx = -1;
	while (++idx < chef->number_of_philo)
	{
		philo_constructor(&(chef->philos[idx]), idx, time_to_eat, time_to_sleep);
		chef->philos[idx].time_to_die = time_to_die;
		chef->philos[idx].fork = chef->forks;
	}
}

void	chef_destructor(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
		philo_destructor(&(chef->philos[idx]));
	free(chef->pids);
	free(chef->philos);
	sem_unlink("forks");
	sem_close(chef->forks);
}