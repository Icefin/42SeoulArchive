/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:57:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/11 00:53:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

void	chef_destructor(t_chef *chef)
{
	
}