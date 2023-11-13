/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:59:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/13 16:30:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
	chef_start_serving(&chef);
	chef_destructor(&chef);
	return (0);
}