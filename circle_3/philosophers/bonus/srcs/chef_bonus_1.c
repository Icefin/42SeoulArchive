/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/11 18:21:55 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "chef_bonus.h"
#include "utils_bonus.h"

void	chef_constructor(t_chef *chef, int argc, char **argv)
{
	int	idx;
	int	time_to_eat;
	int	time_to_sleep;

	chef->number_of_philo = ft_atoi(argv[1]);
	chef->time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	chef->number_of_times_must_eat = -1;
	if (argc == 6)
		chef->number_of_times_must_eat = ft_atoi(argv[5]);
	chef->forks = sem_open("forks", O_CREAT, 0644, chef->number_of_philo);
	chef->states = sem_open("states", O_CREAT, 0644, chef->number_of_philo);
	chef->philos = (t_philo *)malloc(sizeof(t_philo) * chef->number_of_philo);
	idx = -1;
	while (++idx < chef->number_of_philo)
	{
		philo_constructor(&(chef->philos[idx]), idx, time_to_eat, time_to_sleep);
		chef->philos[idx].smp = chef->states;
		chef->philos[idx].fork = chef->forks;
	}
}

void	chef_destructor(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
		philo_destructor(&(chef->philos[idx]));
	free(chef->philos);
	sem_unlink("forks");
	sem_unlink("states");
	sem_close("forks");
	sem_close("states");
}