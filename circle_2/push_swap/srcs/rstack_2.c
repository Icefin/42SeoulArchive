/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:41 by geshin            #+#    #+#             */
/*   Updated: 2023/10/13 01:38:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

#include <stdio.h>

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
	stack->top->next = node;
	stack->top = node;
	stack->size += 1;
}

void	rstack_pop_top(t_rstack *stack)
{
	if (stack->size == 0)
	{
		printf("Error::RPT : Stack is empty\n");
		destroy_rstack(stack);
		exit(0);
	}
	destroy_node(stack->top);
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
	stack->bottom->prev = node;
	stack->bottom = node;
	stack->size += 1;
}

void	rstack_pop_bottom(t_rstack *stack)
{
	if (stack->size == 0)
	{
		printf("Error::RPB : Stack is empty\n");
		destroy_rstack(stack);
		exit(0);
	}
	destroy_node(stack->bottom);
	stack->size -= 1;
}