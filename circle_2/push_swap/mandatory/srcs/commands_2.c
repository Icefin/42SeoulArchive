/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:17:50 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 13:34:29 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	cmd_rotate_a(t_rstack *stack, t_vector *cmd)
{
	t_node	*top;

	if (stack->size <= 1)
		return ;
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

void	cmd_rotate_b(t_rstack *stack, t_vector *cmd)
{
	t_node	*top;

	if (stack->size <= 1)
		return ;
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
	vector_push_back(cmd, RB);
}

void	cmd_rotate_all(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_rotate_a(a, cmd);
	cmd_rotate_b(b, cmd);
	vector_pop_back(cmd);
	vector_pop_back(cmd);
	vector_push_back(cmd, RR);
}
