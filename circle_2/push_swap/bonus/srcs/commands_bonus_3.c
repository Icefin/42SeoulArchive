/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:22:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/22 15:59:20 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands_bonus.h"

void	cmd_reverse_rotate_a_bonus(t_rstack *stack)
{
	t_node	*bottom;

	if (stack->size <= 1)
		return ;
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
}

void	cmd_reverse_rotate_b_bonus(t_rstack *stack)
{
	t_node	*bottom;

	if (stack->size <= 1)
		return ;
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
}

void	cmd_reverse_rotate_all_bonus(t_rstack *a, t_rstack *b)
{
	cmd_reverse_rotate_a_bonus(a);
	cmd_reverse_rotate_b_bonus(b);
}