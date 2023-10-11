/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:31 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 15:03:35 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

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
	t_node	*first;
	t_node	*second;

	if (rstack->size <= 1)
		return ;
	else if (rstack->size == 2)
		cmd_swap_top(rstack);
	else
	{
		
	}
	//top to bottom
}

void	cmd_reverse_rotate(t_rstack *rstack)
{
	t_node	*first;
	t_node	*second;

	if (rstack->size <= 1)
		return ;
	else if (rstack->size == 2)
		cmd_swap_top(rstack);
	else
	{
		
	}
	//bottom to top
}