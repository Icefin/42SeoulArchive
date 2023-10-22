/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:22:48 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 15:59:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands_bonus.h"

void	cmd_swap_top_a_bonus(t_rstack *stack)
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
}

void	cmd_swap_top_b_bonus(t_rstack *stack)
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
}

void	cmd_swap_top_all_bonus(t_rstack *a, t_rstack *b)
{
	cmd_swap_top_a_bonus(a);
	cmd_swap_top_b_bonus(b);
}

void	cmd_push_to_a_bonus(t_rstack *from, t_rstack *to)
{
	int	val;
	
	if (from->size == 0)
		return ;
	val = from->top->value;
	rstack_pop_top(from);
	rstack_push_top(to, val);
}

void	cmd_push_to_b_bonus(t_rstack *from, t_rstack *to)
{
	int	val;
	
	if (from->size == 0)
		return ;
	val = from->top->value;
	rstack_pop_top(from);
	rstack_push_top(to, val);
}