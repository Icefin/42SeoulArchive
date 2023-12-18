/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:49:46 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:29:02 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEF_BONUS_H
# define CHEF_BONUS_H

# include "commontype_bonus.h"
# include "philo_bonus.h"

typedef struct s_chef
{
	int		nump;
	int		dtime;
	int		etime;
	int		stime;

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