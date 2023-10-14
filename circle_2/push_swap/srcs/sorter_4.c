/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:29 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/14 16:28:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	move_rbra_path(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{
	int	rr_cnt;

	if (info->ra_cnt >= info->rb_cnt)
	{
		rr_cnt = info->rb_cnt;
		while (rr_cnt > 0)
		{
			cmd_rotate_all(a_stack, b_stack, cmd);	
			rr_cnt -= 1;
		}
		while (info->ra_cnt > info->rb_cnt)
		{
			cmd_rotate_a(a_stack, cmd);
			info->ra_cnt -= 1;
		}
	}
	else
	{
		rr_cnt = info->ra_cnt;
		while (rr_cnt > 0)
		{
			cmd_rotate_all(a_stack, b_stack, cmd);
			rr_cnt -= 1;
		}
		while (info->rb_cnt-- > info->ra_cnt)
		{
			cmd_rotate_b(b_stack, cmd);
			info->rb_cnt -= 1;
		}
	}
}

static void move_rbrra_path(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{
	while (info->rb_cnt > 0)
	{
		cmd_rotate_b(b_stack, cmd);
		info->rb_cnt -= 1;
	}
	while (info->rra_cnt > 0)
	{
		cmd_reverse_rotate_a(a_stack, cmd);
		info->rra_cnt -= 1;
	}
}

static void move_rrbra_path(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{
	while (info->rrb_cnt > 0)
	{
		cmd_reverse_rotate_b(b_stack, cmd);
		info->rrb_cnt -= 1;
	}
	while (info->ra_cnt > 0)
	{
		cmd_rotate_a(a_stack, cmd);
		info->ra_cnt -= 1;
	}
}

static void	move_rrbrra_path(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{
	int	rrr_cnt;

	if (info->rra_cnt >= info->rrb_cnt)
	{
		rrr_cnt = info->rrb_cnt;
		while (rrr_cnt > 0)
		{
			cmd_reverse_rotate_all(a_stack, b_stack, cmd);
			rrr_cnt -= 1;
		}
		while (info->rra_cnt > info->rrb_cnt)
		{
			cmd_reverse_rotate_a(a_stack, cmd);
			info->rra_cnt -= 1;
		}
	}
	else
	{
		rrr_cnt = info->rra_cnt;
		while (rrr_cnt > 0)
		{
			cmd_reverse_rotate_all(a_stack, b_stack, cmd);
			rrr_cnt -= 1;
		}
		while (info->rrb_cnt > info->rra_cnt)
		{
			cmd_reverse_rotate_b(b_stack, cmd);
			info->rrb_cnt -= 1;
		}
	}
}

void	move_optimal_node(t_rstack *a_stack, t_rstack *b_stack, t_dist_info *info, t_vector *cmd)
{
	if (info->path == RBRA)
		move_rbra_path(a_stack, b_stack, info, cmd);
	else if (info->path == RBRRA)
		move_rbrra_path(a_stack, b_stack, info, cmd);
	else if (info->path == RRBRA)
		move_rrbra_path(a_stack, b_stack, info, cmd);
	else if (info->path == RRBRRA)
		move_rrbrra_path(a_stack, b_stack, info, cmd);
	cmd_push_to_a(b_stack, a_stack, cmd);
}