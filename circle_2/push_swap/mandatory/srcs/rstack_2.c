/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:41 by geshin            #+#    #+#             */
/*   Updated: 2023/10/22 16:38:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

void	rstack_push_top(t_rstack *stack, int val)
{
	t_node	*node;

	if (stack->size == 0)
	{
		node = create_node(val, NULL, NULL);
		stack->top = node;
		stack->bottom = node;
		stack->size = 1;
		return ;
	}
	node = create_node(val, NULL, stack->top);
	if (stack->size == 1)
		stack->bottom->next = node;
	else if (stack->size > 1)
		stack->top->next = node;
	stack->top = node;
	stack->size += 1;
}

void	rstack_pop_top(t_rstack *stack)
{
	t_node	*node;

	if (stack->size == 0)
	{
		destroy_rstack(stack);
		exit(0);
	}
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else if (stack->size == 2)
	{
		stack->top = stack->bottom;
		stack->bottom->next = NULL;
	}
	else
	{
		stack->top = stack->top->prev;
		stack->top->next = NULL;
	}
	destroy_node(node);
	stack->size -= 1;
}

void	rstack_push_bottom(t_rstack *stack, int val)
{
	t_node	*node;

	if (stack->size == 0)
	{
		node = create_node(val, NULL, NULL);
		stack->top = node;
		stack->bottom = node;
		stack->size = 1;
		return ;
	}
	node = create_node(val, stack->bottom, NULL);
	if (stack->size == 1)
		stack->top->prev = node;
	else if (stack->size > 1)
		stack->bottom->prev = node;
	stack->bottom = node;
	stack->size += 1;
}

void	rstack_pop_bottom(t_rstack *stack)
{
	t_node	*node;

	if (stack->size == 0)
	{
		destroy_rstack(stack);
		exit(0);
	}
	node = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else if (stack->size == 2)
	{
		stack->top = stack->bottom;
		stack->bottom->next = NULL;
	}
	else
	{
		stack->bottom = stack->bottom->next;
		stack->bottom->prev = NULL;
	}
	destroy_node(node);
	stack->size -= 1;
}