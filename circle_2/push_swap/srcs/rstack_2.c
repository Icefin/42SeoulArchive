/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:41 by geshin            #+#    #+#             */
/*   Updated: 2023/09/27 18:02:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

void	rstack_push_top(t_rstack *rstack, t_node *node)
{
	if (rstack->size == 0)
	{
		rstack->bottom = node;
		rstack->top = node;
	}
	else
		;
}

void	rstack_pop_top(t_rstack *rstack)
{
	t_node	*temp;

	if (rstack->size == 0)
	{
		printf("Error::RPT : Stack is empty\n");
		exit(0);
	}
	temp = rstack->top;
	rstack->top = rstack->top->prev;
	rstack->top->next = NULL;
}

void	rstack_push_bottom(t_rstack *rstack, t_node *node)
{
	if (rstack->size == 0)
	{
		rstack->bottom = node;
		rstack->top = node;
	}
	else
		;
}

void	rstack_pop_bottom(t_rstack *rstack)
{
	t_node	*temp;

	if (rstack->size == 0)
	{
		printf("Error::RPB : Stack is empty\n");
		exit(0);
	}
	temp = rstack->bottom;
	rstack->bottom = rstack->bottom->next;
	rstack->bottom->prev = NULL;
}