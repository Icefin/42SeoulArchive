/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:49:46 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/11 13:10:58 by singeonho        ###   ########.fr       */
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
	t_int64	time_to_die;

	sem_t	*forks;
	sem_t	*states;
	t_philo	*philos;
}	t_chef;

void	chef_constructor(t_chef *chef, int argc, char **argv);
void	chef_destructor(t_chef *chef);

#endif