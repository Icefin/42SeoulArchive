/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:31 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 17:50:55 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

//RECHECK HERE
void	cmd_swap_top(t_rstack *rstack)
{
	t_node	*first;
	t_node	*second;

	if (rstack->size <= 1)
		return ;
	else if (rstack->size == 2)
	{
		first = rstack->top;
		second = rstack->bottom;
		
		first->next = second;
		first->prev = NULL;
		second->next = NULL;
		second->prev = first;
		
		rstack->top = second;
		rstack->bottom = first;
	}
	else
	{
		first = rstack->top;
		second = rstack->top->prev;

		first->next = second;
		first->prev = second->prev;
		second->next = NULL;
		second->prev = first;
		
		rstack->top = second;
	}
}

void	cmd_pop_and_push(t_rstack *from, t_rstack *to)
{
	int	val;
	
	if (from->size == 0)
		return ;
	val = from->top->value;
	rstack_pop_top(from);
	rstack_push_top(to, val);
}

void	cmd_rotate(t_rstack *rstack)
{
	t_node	*top;

	if (rstack->size <= 1)
		return ;
	else if (rstack->size == 2)
		cmd_swap_top(rstack);
	else
	{
		top = rstack->top;

		rstack->top = top->prev;
		top->prev->next = NULL;
		top->prev = NULL;
		top->next = rstack->bottom;
		rstack->bottom->prev = top;
	}
}

void	cmd_reverse_rotate(t_rstack *rstack)
{
	t_node	*bottom;

	if (rstack->size <= 1)
		return ;
	else if (rstack->size == 2)
		cmd_swap_top(rstack);
	else
	{
		bottom = rstack->bottom;

		rstack->bottom = bottom->next;
		bottom->next->prev = NULL;
		bottom->next = NULL;
		bottom->prev = rstack->top;
		rstack->top->next = bottom;
	}
}