/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/13 14:27:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	get_optimal_distance_from_a_stack()
{

}

static void	get_optimal_distance_from_b_stack()
{

}

static void	move_optimal_node()
{

}

void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector* cmd)
{
	int		i;
	t_node	*node;

	while (b_stack->size > 0)
	{
		i = 0;
		node = b_stack->bottom;
		while (node != NULL)
		{
			
			i++;
			node = node->next;
		}
	}
}