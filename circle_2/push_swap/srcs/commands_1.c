/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/15 15:02:10 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	cmd_swap_top_a(t_rstack *stack, t_vector *cmd)
{
	t_node	*temp;

	if (stack->size <= 1)
		return ;
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

	if (stack->size <= 1)
	{
		vector_push_back(cmd, RA);
		return ;
	}
	top = stack->top;
	if (stack->size == 2)
	{
		stack->top->next = stack->bottom;
		stack->top->prev = NULL;
		stack->bottom->prev = stack->top;
		stack->bottom->next = NULL;
		stack->top = stack->bottom;
		stack->bottom = top;
	}
	else
	{
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

	if (stack->size <= 1)
	{
		vector_push_back(cmd, RRA);
		return ;
	}
	bottom = stack->bottom;
	if (stack->size == 2)
	{
		stack->top->next = stack->bottom;
		stack->top->prev = NULL;
		stack->bottom->prev = stack->top;
		stack->bottom->next = NULL;
		stack->bottom = stack->top;
		stack->top = bottom;
	}
	else
	{
		stack->bottom = bottom->next;
		stack->bottom->prev = NULL;
		bottom->next = NULL;
		bottom->prev = stack->top;
		stack->top->next = bottom;
		stack->top = bottom;
	}
	vector_push_back(cmd, RRA);
}

void	cmd_rotate_all(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_rotate_a(a, cmd);
	cmd_rotate_b(b, cmd);
	vector_pop_back(cmd);
	vector_pop_back(cmd);
	vector_push_back(cmd, RR);
}