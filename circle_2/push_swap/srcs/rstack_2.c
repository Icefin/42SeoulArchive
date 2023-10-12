/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:41 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 16:10:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

#include <stdio.h>

void	rstack_push_top(t_rstack *rstack, int val)
{
	t_node	*node;

	if (rstack->size == 0)
	{
		node = create_node(val, NULL, NULL);
		rstack->top = node;
		rstack->bottom = node;
		rstack->size = 1;
		return ;
	}
	node = create_node(val, NULL, rstack->top);
	rstack->top->next = node;
	rstack->top = node;
	rstack->size += 1;
}

void	rstack_pop_top(t_rstack *rstack)
{
	if (rstack->size == 0)
	{
		printf("Error::RPT : Stack is empty\n");
		destroy_rstack(rstack);
		exit(0);
	}
	destroy_node(rstack->top);
	rstack->size -= 1;
}

void	rstack_push_bottom(t_rstack *rstack, int val)
{
	t_node	*node;

	if (rstack->size == 0)
	{
		node = create_node(val, NULL, NULL);
		rstack->top = node;
		rstack->bottom = node;
		rstack->size = 1;
		return ;
	}
	node = create_node(val, rstack->bottom, NULL);
	rstack->bottom->prev = node;
	rstack->bottom = node;
	rstack->size += 1;
}

void	rstack_pop_bottom(t_rstack *rstack)
{
	if (rstack->size == 0)
	{
		printf("Error::RPB : Stack is empty\n");
		destroy_rstack(rstack);
		exit(0);
	}
	destroy_node(rstack->bottom);
	rstack->size -= 1;
}