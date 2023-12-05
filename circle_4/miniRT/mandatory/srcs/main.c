/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/06 00:04:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "commontype.h"
#include "minirt.h"

static t_bool	is_valid_arguments(int argc, char **argv)
{
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_minirt	minirt;

	if (is_valid_arguments(argc, argv) == FALSE)
	{
		printf("Invalid Argument Input\n");
		return (0);
	}
	initialize_minirt(&minirt);
	begin_minirt(&minirt);
	destroy_minirt(&minirt);
	return (0);
}