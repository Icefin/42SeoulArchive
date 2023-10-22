/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:42:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 17:00:04 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

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

void	cmd_reverse_rotate_b(t_rstack *stack, t_vector *cmd)
{
	t_node	*bottom;

	if (stack->size <= 1)
	{
		vector_push_back(cmd, RRB);
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
	vector_push_back(cmd, RRB);
}

void	cmd_reverse_rotate_all(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_reverse_rotate_a(a, cmd);
	cmd_reverse_rotate_b(b, cmd);
	vector_pop_back(cmd);
	vector_pop_back(cmd);
	vector_push_back(cmd, RRR);
}
