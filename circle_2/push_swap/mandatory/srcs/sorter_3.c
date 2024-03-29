/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 14:15:05 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

void	move_node(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd);

static int	get_ra_cnt(t_rstack *a, int b_value)
{
	t_node	*node;
	int		idx;
	int		min_idx;
	int		min_value;

	node = a->top->prev;
	idx = 1;
	min_idx = 0;
	min_value = a->top->value;
	while (node != NULL)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_idx = idx;
		}
		if (node->next->value < b_value && node->value > b_value)
			return (idx);
		node = node->prev;
		idx += 1;
	}
	return (min_idx);
}

static void	update_current_info(t_rstack *a, t_rstack *b, t_dist_info *info)
{
	info->rrb_cnt = b->size - info->idx;
	info->rb_cnt = info->idx;
	if (a->top->value > info->node->value
		&& a->bottom->value < info->node->value)
	{
		info->rra_cnt = 0;
		info->ra_cnt = 0;
		return ;
	}
	info->ra_cnt = get_ra_cnt(a, info->node->value);
	info->rra_cnt = a->size - info->ra_cnt;
}

static int	get_min_distance(t_dist_info *info)
{
	int	rbra;
	int	rrbrra;
	int	min_dist;

	rbra = info->rb_cnt;
	if (info->ra_cnt > info->rb_cnt)
		rbra = info->ra_cnt;
	rrbrra = info->rrb_cnt;
	if (info->rra_cnt > info->rrb_cnt)
		rrbrra = info->rra_cnt;
	min_dist = rbra;
	if (min_dist > info->rb_cnt + info->rra_cnt)
		min_dist = info->rb_cnt + info->rra_cnt;
	if (min_dist > info->rrb_cnt + info->ra_cnt)
		min_dist = info->rrb_cnt + info->ra_cnt;
	if (min_dist > rrbrra)
		min_dist = rrbrra;
	info->path = RBRA;
	if (min_dist == rrbrra)
		info->path = RRBRRA;
	if (min_dist == info->rb_cnt + info->rra_cnt)
		info->path = RBRRA;
	if (min_dist == info->rrb_cnt + info->ra_cnt)
		info->path = RRBRA;
	return (min_dist);
}

static void	update_optimal_info(t_dist_info *optimal, t_dist_info *compare)
{
	int	optimal_dist;
	int	compare_dist;

	optimal_dist = get_min_distance(optimal);
	compare_dist = get_min_distance(compare);
	if (compare_dist <= optimal_dist)
	{
		optimal->idx = compare->idx;
		optimal->node = compare->node;
		optimal->ra_cnt = compare->ra_cnt;
		optimal->rb_cnt = compare->rb_cnt;
		optimal->rra_cnt = compare->rra_cnt;
		optimal->rrb_cnt = compare->rrb_cnt;
		optimal->path = compare->path;
	}
}

void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd)
{
	t_dist_info	optimal_info;
	t_dist_info	curr_info;

	while (b_stack->size > 0)
	{
		curr_info.idx = 0;
		curr_info.node = b_stack->top;
		optimal_info.ra_cnt = 2 * a_stack->size;
		optimal_info.rb_cnt = 2 * b_stack->size;
		optimal_info.rra_cnt = 2 * a_stack->size;
		optimal_info.rrb_cnt = 2 * b_stack->size;
		while (curr_info.node != NULL)
		{
			update_current_info(a_stack, b_stack, &curr_info);
			update_optimal_info(&optimal_info, &curr_info);
			curr_info.idx += 1;
			curr_info.node = curr_info.node->prev;
		}
		move_node(a_stack, b_stack, &optimal_info, cmd);
	}
}
