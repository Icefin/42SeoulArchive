/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chef.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:13:03 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/10 20:59:26 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEF_H
# define CHEF_H

# include "commontype.h"
# include "philo.h"

typedef struct s_chef
{
	int				number_of_philo;
	int				number_of_times_must_eat;
	long long		time_to_die;

	pthread_mutex_t	*forks;
	pthread_mutex_t	*states;
	t_philo			*philos;
}	t_chef;

void	chef_constructor(t_chef *chef, int argc, char **argv);
void	chef_destructor(t_chef *chef);

void	chef_start_serving(t_chef *chef);
t_bool	chef_check_is_philo_ok(t_chef *chef);
void	chef_stop_serving(t_chef *chef);

#endif