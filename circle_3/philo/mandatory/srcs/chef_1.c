/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:23:39 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/08 17:50:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "chef.h"

void	chef_constructor(t_chef *chef, int argc, char **argv)
{
	int	idx;

	chef->number_of_philo = ft_atoi(argv[1]);
	chef->time_to_die = ft_atoi(argv[2]);
	chef->time_to_eat = ft_atoi(argv[3]);
	chef->time_to_sleep = ft_atoi(argv[4]);
	chef->number_of_times_must_eat = -1;
	if (argc == 6)
		chef->number_of_times_must_eat = ft_atoi(argv[5]);
	
	chef->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * chef->number_of_philo);
	chef->philos = (t_philo *)malloc(sizeof(t_philo) * chef->number_of_philo);
	idx = -1;
	while (++idx < chef->number_of_philo)
		pthread_mutex_init(&(chef->forks[idx]), NULL);
	idx = -1;
	while (++idx < chef->number_of_philo)
		philo_constructor(&(chef->philos[idx]), idx, &(chef->forks[idx]), &(chef->forks[(idx + 1) % chef->number_of_philo]));
}

void	chef_destructor(t_chef *chef)
{
	int	idx;

	idx = -1;
	while (++idx < chef->number_of_philo)
	{
		philo_destructor(&(chef->philos[idx]));
		pthread_mutex_destroy(&(chef->forks[idx]));
	}
	free(chef->philos);
	free(chef->forks);
}