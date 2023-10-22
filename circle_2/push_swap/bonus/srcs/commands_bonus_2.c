/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:22:50 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 15:59:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands_bonus.h"

void	cmd_rotate_a_bonus(t_rstack *stack)
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
}

void	cmd_rotate_b_bonus(t_rstack *stack)
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
}

void	cmd_rotate_all_bonus(t_rstack *a, t_rstack *b)
{
	cmd_rotate_a_bonus(a);
	cmd_rotate_b_bonus(b);
}