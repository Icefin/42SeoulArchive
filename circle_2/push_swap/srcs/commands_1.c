/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/12 16:41:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//RECHECK HERE
//COMMANDS A
void	cmd_swap_top_a(t_rstack *rstack, t_vector *cmd)
{
	t_node	*first;
	t_node	*second;

	if (rstack->size == 2)
	{
		first = rstack->top;
		second = rstack->bottom;
		first->next = second;
		first->prev = NULL;
		second->next = NULL;
		second->prev = first;
		rstack->top = second;
		rstack->bottom = first;
	}
	else
	{
		first = rstack->top;
		second = rstack->top->prev;
		first->next = second;
		first->prev = second->prev;
		second->next = NULL;
		second->prev = first;
		rstack->top = second;
	}
	vector_push_back(cmd, SA);
}

void	cmd_push_to_a(t_rstack *from, t_rstack *to, t_vector *cmd)
{
	int	val;
	
	if (from->size == 0)
		return ;
	val = from->top->value;
	rstack_pop_top(from);
	rstack_push_top(to, val);
	vector_push_back(cmd, PA);
}

void	cmd_rotate_a(t_rstack *stack, t_vector *cmd)
{
	t_node	*top;

	if (stack->size == 2)
	{

	}
	else
	{
		top = stack->top;

		stack->top = top->prev;
		stack->top->next = NULL;
		top->prev = NULL;
		top->next = stack->bottom;
		stack->bottom->prev = top;
		stack->bottom = top;
	}
	vector_push_back(cmd, RA);
}

void	cmd_reverse_rotate_a(t_rstack *stack, t_vector *cmd)
{
	t_node	*bottom;

	if (stack->size == 2)
	{
		
	}
	else
	{
		bottom = stack->bottom;

		stack->bottom = bottom->next;
		stack->bottom->prev = NULL;
		bottom->next = NULL;
		bottom->prev = stack->top;
		stack->top->next = bottom;
		stack->top = bottom;
	}
	vector_push_back(cmd, RRA);
}