/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_bonus_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:43 by geshin            #+#    #+#             */
/*   Updated: 2023/10/22 16:04:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack_bonus.h"

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

void	init_rstack(t_rstack *stack)
{
	stack->bottom = NULL;
	stack->top = NULL;
	stack->size = 0;
}

void	destroy_rstack(t_rstack *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack->bottom;
	while (curr != NULL)
	{
		next = curr->next;
		destroy_node(curr);
		curr = next;
	}
}