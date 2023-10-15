/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:29 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/15 15:06:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	rbra_path(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	int	rr_cnt;

	if (info->ra_cnt >= info->rb_cnt)
	{
		rr_cnt = info->rb_cnt;
		while (rr_cnt > 0)
		{
			cmd_rotate_all(a, b, cmd);	
			rr_cnt -= 1;
		}
		while (info->ra_cnt > info->rb_cnt)
		{
			cmd_rotate_a(a, cmd);
			info->ra_cnt -= 1;
		}
	}
	else
	{
		rr_cnt = info->ra_cnt;
		while (rr_cnt > 0)
		{
			cmd_rotate_all(a, b, cmd);
			rr_cnt -= 1;
		}
		while (info->rb_cnt > info->ra_cnt)
		{
			cmd_rotate_b(b, cmd);
			info->rb_cnt -= 1;
		}
	}
}

static void rbrra_path(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	while (info->rb_cnt > 0)
	{
		cmd_rotate_b(b, cmd);
		info->rb_cnt -= 1;
	}
	while (info->rra_cnt > 0)
	{
		cmd_reverse_rotate_a(a, cmd);
		info->rra_cnt -= 1;
	}
}

static void rrbra_path(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	while (info->rrb_cnt > 0)
	{
		cmd_reverse_rotate_b(b, cmd);
		info->rrb_cnt -= 1;
	}
	while (info->ra_cnt > 0)
	{
		cmd_rotate_a(a, cmd);
		info->ra_cnt -= 1;
	}
}

static void	rrbrra_path(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	int	rrr_cnt;

	if (info->rra_cnt >= info->rrb_cnt)
	{
		rrr_cnt = info->rrb_cnt;
		while (rrr_cnt > 0)
		{
			cmd_reverse_rotate_all(a, b, cmd);
			rrr_cnt -= 1;
		}
		while (info->rra_cnt > info->rrb_cnt)
		{
			cmd_reverse_rotate_a(a, cmd);
			info->rra_cnt -= 1;
		}
	}
	else
	{
		rrr_cnt = info->rra_cnt;
		while (rrr_cnt > 0)
		{
			cmd_reverse_rotate_all(a, b, cmd);
			rrr_cnt -= 1;
		}
		while (info->rrb_cnt > info->rra_cnt)
		{
			cmd_reverse_rotate_b(b, cmd);
			info->rrb_cnt -= 1;
		}
	}
}

void	move_optimal_node(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	if (info->path == RBRA)
		rbra_path(a, b, info, cmd);
	else if (info->path == RBRRA)
		rbrra_path(a, b, info, cmd);
	else if (info->path == RRBRA)
		rrbra_path(a, b, info, cmd);
	else if (info->path == RRBRRA)
		rrbrra_path(a, b, info, cmd);
	cmd_push_to_a(b, a, cmd);
}