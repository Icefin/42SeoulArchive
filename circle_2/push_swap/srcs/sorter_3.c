/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/13 15:00:23 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	get_distance_info(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *curr)
{
	t_node	*node;
	int		i;

	curr->b_to_lower = curr->idx;
	curr->b_to_upper = b_stack->size - curr->idx;
	node = a_stack->bottom;
	while (node != NULL)
	{
		if (node->value > curr->node->value)
		{
			curr->a_to_lower = 0;
			curr->a_to_upper = 0;
			break ;
		}
		i++;
		node = node->next;
	}
}

static void	get_optimal_info(t_dist_info *optimal, t_dist_info *curr)
{
	
}

static void	move_optimal_node(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{

}

static void	rotate_ascending_order(t_rstack *stack, t_vector *cmd)
{
	
}

void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd)
{
	t_dist_info	optimal_info;
	t_dist_info	curr_info;

	while (b_stack->size > 0)
	{
		curr_info.idx = 0;
		curr_info.node = b_stack->bottom;
		while (curr_info.node != NULL)
		{
			get_distance_info(a_stack, b_stack, &curr_info);
			get_optimal_info(&optimal_info, &curr_info);
			curr_info.idx++;
			curr_info.node = curr_info.node->next;
		}
		move_optimal_node(a_stack, b_stack, &optimal_info, cmd);
	}
	rotate_ascending_order(a_stack, cmd);
}