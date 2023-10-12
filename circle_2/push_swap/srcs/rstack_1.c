/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:43 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 16:26:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

t_node	*create_node(int value, t_node *next, t_node *prev)
{
	t_node	*res;

	res = (t_node *)malloc(sizeof(t_node));
	res->next = next;
	res->prev = prev;
	res->value = value;
	return (res);
}

void	destroy_node(t_node *node)
{
	free(node);
}

void	init_rstack(t_rstack *rstack)
{
	rstack->bottom = NULL;
	rstack->top = NULL;
	rstack->size = 0;
}

void	destroy_rstack(t_rstack *rstack)
{
	t_node	*curr;
	t_node	*next;

	curr = rstack->bottom;
	while (curr != NULL)
	{
		next = curr->next;
		destroy_node(curr);
		curr = next;
	}
}