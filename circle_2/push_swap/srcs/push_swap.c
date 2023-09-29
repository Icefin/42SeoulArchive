/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:13:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/29 17:17:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"
#include "vector.h"

#include "parser.h"
#include "sorter.h"
#include "optimizer.h"
#include "displayer.h"

#include <stdio.h>

#define FALSE	0
#define TRUE	1

static int	is_sorted(t_rstack *stack)
{
	int		prev;
	t_node	*curr;

	prev = stack->top->value;
	curr = stack->top->prev;	
	while (curr != NULL)
	{
		if (prev > curr->value)
			return (FALSE);
		prev = curr->value;
		curr = curr->prev;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_rstack	stack;
	t_vector	commands;

	if (argc == 0)
	{
		printf("Error : This program requires at least one argument\n");
		return;
	}
	init_rstack(&stack);
	parse_arguments(argc, argv, &stack);
	if (is_sorted(&stack) == TRUE)
	{
		destroy_rstack(&stack);
		printf("Stack is already sorted\n");
		return;
	}
	while (TRUE) ;
	sort_stack(&stack, &commands);
	if (is_sorted(&stack) == FALSE)
	{
		destroy_rstack(&stack);
		destroy_vector(&commands);
		printf("Error : Stack is not sorted! Check sorting step again\n");
		return;
	}
	//while (TRUE) ;
	optimize_commands(&commands);
	display_commands(&commands);
	destroy_rstack(&stack);
	destroy_vector(&commands);
	return (0);
}
