/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:59:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/09 00:54:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "commontype_bonus.h"
#include "chef_bonus.h"

static t_bool	is_valid_argument(int argc)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_chef	chef;
	
	if (is_valid_argument(argc) == FALSE)
	{
		printf("Invalid Argument Input\n");
		return (0);
	}
	chef_constructor(&chef, argc, argv);
	printf("Serving start\n");
	chef_start_serving(&chef);
	while (TRUE)
	{
		if (chef_check_is_philo_ok(&chef) == FALSE)
			break ;
	}
	chef_destructor(&chef);
	return (0);
}