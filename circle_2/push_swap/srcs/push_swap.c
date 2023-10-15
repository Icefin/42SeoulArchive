/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:13:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/15 15:00:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"
#include "vector.h"
#include "parser.h"
#include "sorter.h"
#include "displayer.h"

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
	
	if (argc == 1)
		return (0);
	init_rstack(&stack);
	parse_arguments(argc, argv, &stack);

	if (stack.size <= 1 || is_sorted(&stack) == TRUE)
	{
		destroy_rstack(&stack);
		return (0);
	}
	malloc_vector(&commands, stack.size * 10);
	sort_stack(&stack, &commands);
	display_commands(&commands);
	destroy_rstack(&stack);
	destroy_vector(&commands);
	return (0);
}