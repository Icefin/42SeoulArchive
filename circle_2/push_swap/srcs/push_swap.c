/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:13:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/27 15:23:27 by geshin           ###   ########.fr       */
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

	parse_arguments(argc, argv, &stack);
	if (is_sorted(&stack) == TRUE)
		return;
	sort_elements(&stack, &commands);
	if (is_sorted(&stack) == FALSE)
	{
		printf("Stack is not sorted! Check sorting step again\n");
		return;
	}
	optimize_commands(&commands);
	display_commands(&commands);
	return (0);
}
