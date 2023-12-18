/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:59:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 13:26:52 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "chef.h"
#include "utils.h"

static t_bool	is_valid_argument(int argc)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_chef	chef;

	if (is_valid_argument(argc) == FALSE)
	{
		printf("Invalid Argument Input\n");
		return (0);
	}
	chef_constructor(&chef, argc, argv);
	chef_start_serving(&chef);
	while (TRUE)
	{
		if (chef_check_is_philo_ok(&chef) == FALSE)
		{
			chef_stop_serving(&chef);
			break ;
		}
		usleep(100);
	}
	chef_destructor(&chef);
	return (0);
}
