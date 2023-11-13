/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:49:46 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/13 16:50:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEF_BONUS_H
# define CHEF_BONUS_H

# include "commontype_bonus.h"
# include "philo_bonus.h"

typedef struct s_chef
{
	int		number_of_philo;
	int		number_of_times_must_eat;

	sem_t	*forks;
	pid_t	*pids;
	t_philo	*philos;
}	t_chef;

void	chef_constructor(t_chef *chef, int argc, char **argv);
void	chef_destructor(t_chef *chef);

void	chef_start_serving(t_chef *chef);
t_bool	chef_check_is_philo_ok(t_chef *chef);
void	chef_stop_serving(t_chef *chef);

#endif