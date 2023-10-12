/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:17:50 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/12 16:21:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//RECHECK HERE
//COMMANDS B
void	cmd_swap_top_b(t_rstack *rstack, t_vector *cmd)
{
	t_node	*first;
	t_node	*second;

	if (rstack->size == 2)
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
	vector_push_back(cmd, SB);
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

void	cmd_rotate_b(t_rstack *rstack, t_vector *cmd)
{
	t_node	*top;

	if (rstack->size == 2)
	{

	}
	else
	{
		top = rstack->top;

		rstack->top = top->prev;
		top->prev->next = NULL;
		top->prev = NULL;
		top->next = rstack->bottom;
		rstack->bottom->prev = top;
	}
	vector_push_back(cmd, RB);
}

void	cmd_reverse_rotate_b(t_rstack *rstack, t_vector *cmd)
{
	t_node	*bottom;

	if (rstack->size == 2)
	{
		
	}
	else
	{
		bottom = rstack->bottom;

		rstack->bottom = bottom->next;
		bottom->next->prev = NULL;
		bottom->next = NULL;
		bottom->prev = rstack->top;
		rstack->top->next = bottom;
	}
	vector_push_back(cmd, RRB);
}