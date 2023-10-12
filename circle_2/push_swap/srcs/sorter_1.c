/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:15:50 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 16:38:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

#include <stdio.h>

static void	sort_size_two(t_rstack *stack, t_vector *cmd)
{
	if (stack->top->value < stack->bottom->value)
		return ;
	cmd_swap_top_a(stack, cmd);
}

//sort size three stack with optimal command number
static void	sort_size_three(t_rstack *stack, t_vector *cmd)
{
	//t   b
	//2 3 1
	if (stack->top->prev->value > stack->top->value 
		&& stack->top->value > stack->bottom->value)
		cmd_reverse_rotate_a(stack, cmd);
	//3 1 2
	else if (stack->top->value > stack->bottom->value
		&& stack->bottom->value > stack->top->prev->value)
		cmd_rotate_a(stack, cmd);
	//1 3 2
	else if (stack->top->prev->value > stack->bottom->value
		&& stack->bottom->value > stack->top->value)
	{
		cmd_reverse_rotate_a(stack, cmd);
		cmd_swap_top_a(stack, cmd);
	}
	//2 1 3
	else if (stack->bottom->value > stack->top->value
		&& stack->top->value > stack->top->prev->value)
		cmd_swap_top_a(stack, cmd);
	//3 2 1
	else if (stack->top->value > stack->top->prev->value
		&& stack->top->prev->value > stack->bottom->value)
	{
		cmd_swap_top_a(stack, cmd);
		cmd_reverse_rotate_a(stack, cmd);
	}
}

static void	process_small_size(t_rstack *stack, t_vector *cmd)
{
	if (stack->size == 2)
		sort_size_two(stack, cmd);
	else if (stack->size == 3)
		sort_size_three(stack, cmd);
}

void	sort_stack(t_rstack *stack, t_vector *out)
{
	t_rstack	b_stack;

	if (stack->size <= 3)
	{
		process_small_size(stack, out);
		return;
	}
	init_rstack(&b_stack);
	process_divide(stack, &b_stack, out);
	process_merge(stack, &b_stack, out);
}