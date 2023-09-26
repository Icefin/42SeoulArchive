/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:13:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/26 13:51:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

#define FALSE	0
#define TRUE	1

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc < 3)
	{
		printf("Not Enough Argument\n");
		return (1);
	}
	
	if (program_parse(&program, argc, argv) == FALSE)
	{
		printf("Prasing Error\n");
		return (1);
	}
	if (program_sort(&program) == FALSE)
	{
		printf("Sorting Error\n");
		return (1);
	}
	if (program_display(&program) == FALSE)
	{
		printf("Display Error\n");
		return (1);
	}
	return (0);
}
