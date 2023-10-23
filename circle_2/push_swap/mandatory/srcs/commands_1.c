/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 13:32:21 by geshin           ###   ########.fr       */
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

void	cmd_swap_top_b(t_rstack *stack, t_vector *cmd)
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
	vector_push_back(cmd, SB);
}

void	cmd_swap_top_all(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_swap_top_a(a, cmd);
	cmd_swap_top_b(b, cmd);
	vector_pop_back(cmd);
	vector_pop_back(cmd);
	vector_push_back(cmd, SS);
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
