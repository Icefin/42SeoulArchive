/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:17:50 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/13 01:36:50 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//RECHECK HERE
void	cmd_swap_top_b(t_rstack *stack, t_vector *cmd)
{
	t_node	*temp;

	if (stack->size == 2)
	{
		temp = stack->top;
		stack->top->next = stack->bottom;
		stack->bottom->prev = stack->top;
		stack->top->prev = NULL;
		stack->bottom->next = NULL;
		stack->top = stack->bottom;
		stack->bottom = temp;
	}
	else
	{
		temp = stack->top->prev;
		stack->top->prev->prev->next = stack->top;
		stack->top->prev = stack->top->prev->prev;
		temp->prev = stack->top;
		temp->next = NULL;
		stack->top->next = temp;
		stack->top = temp;
	}
	vector_push_back(cmd, SB);
}

void	cmd_push_to_b(t_rstack *from, t_rstack *to, t_vector *cmd)
{
	int	val;
	
	if (from->size == 0)
		return ;
	val = from->top->value;
	rstack_pop_top(from);
	rstack_push_top(to, val);
	vector_push_back(cmd, PB);
}

void	cmd_rotate_b(t_rstack *stack, t_vector *cmd)
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
	vector_push_back(cmd, RB);
}

void	cmd_reverse_rotate_b(t_rstack *stack, t_vector *cmd)
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
	vector_push_back(cmd, RRB);
}
