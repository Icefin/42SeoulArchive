/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/14 17:27:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG_SORTER

#include "sorter.h"
#include "commands.h"

void move_optimal_node(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd);

//TODO RECHECK HERE
static void	get_distance_info(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *curr)
{
	t_node	*node;
	int		i;
	int		min_idx;
	int		min_value;

	curr->rrb_cnt = curr->idx + 1;
	if (b_stack->size == 1)
		curr->rrb_cnt = 0;
	curr->rb_cnt = b_stack->size - curr->idx - 1;
	i = 0;
	node = a_stack->top;
	min_idx = -1;
	min_value = 1e9;
	while (node != NULL)
	{
		if (min_value > node->value)
		{
			min_idx = i;
			min_value = node->value;
		}
		if (node->value > curr->node->value)
		{
			curr->rra_cnt = a_stack->size - i;
			curr->ra_cnt = i;
			return ;
		}
		i++;
		node = node->prev;
	}
	curr->rra_cnt = a_stack->size - min_idx;
	curr->ra_cnt = min_idx;
}

static int	get_min_distance(t_dist_info *info)
{
	int	rbra;
	int	rrbrra;
	int	rbrra;
	int	rrbra;
	int	min_dist;

	rbra = info->rb_cnt;
	if (info->ra_cnt > info->rb_cnt)
		rbra = info->ra_cnt;
	rrbrra = info->rrb_cnt;
	if (info->rra_cnt > info->rrb_cnt)
		rrbrra = info->rra_cnt;
	rbrra = info->rb_cnt + info->rra_cnt;
	rrbra = info->rrb_cnt + info->ra_cnt;
	min_dist = rbra;
	info->path = RBRA;
	if (min_dist > rbrra)
	{
		min_dist = rbrra;
		info->path = RBRRA;
	}
	if (min_dist > rrbra)
	{
		min_dist = rrbra;
		info->path = RRBRA;
	}
	if (min_dist > rrbrra)
	{
		min_dist = rrbrra;
		info->path = RRBRRA;
	}
	return (min_dist);
}

static void	update_optimal_info(t_dist_info *optimal, t_dist_info *compare)
{
	int	optimal_dist;
	int	compare_dist;

	optimal_dist = get_min_distance(optimal);
	compare_dist = get_min_distance(compare);
	if (compare_dist <= optimal_dist)
		*optimal = *compare;
}

void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd)
{
	t_dist_info	optimal_info;
	t_dist_info	curr_info;

	while (b_stack->size > 0)
	{
		curr_info.idx = 0;
		curr_info.node = b_stack->bottom;
		optimal_info.ra_cnt = a_stack->size;
		optimal_info.rb_cnt = b_stack->size;
		optimal_info.rra_cnt = a_stack->size;
		optimal_info.rrb_cnt = b_stack->size;
		while (curr_info.node != NULL)
		{
			get_distance_info(a_stack, b_stack, &curr_info);
			update_optimal_info(&optimal_info, &curr_info);
			curr_info.idx += 1;
			curr_info.node = curr_info.node->next;
		}

#ifdef DEBUG_SORTER
	printf("\nOptimal Info\n");
	printf("Optimal Node Value : %d\n", optimal_info.node->value);
	printf("Optimal ra_cnt : %d\n", optimal_info.ra_cnt);
	printf("Optimal rb_cnt : %d\n", optimal_info.rb_cnt);
	printf("Optimal rra_cnt : %d\n", optimal_info.rra_cnt);
	printf("Optimal rrb_cnt : %d\n", optimal_info.rrb_cnt);
#endif

		move_optimal_node(a_stack, b_stack, &optimal_info, cmd);
	}
}