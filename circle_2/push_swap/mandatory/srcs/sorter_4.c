/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:29 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 13:50:43 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	rbra(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	int	rr_cnt;

	if (info->ra_cnt >= info->rb_cnt)
	{
		rr_cnt = info->rb_cnt;
		while (rr_cnt-- > 0)
			cmd_rotate_all(a, b, cmd);
		while (info->ra_cnt-- > info->rb_cnt)
			cmd_rotate_a(a, cmd);
	}
	else
	{
		rr_cnt = info->ra_cnt;
		while (rr_cnt-- > 0)
			cmd_rotate_all(a, b, cmd);
		while (info->rb_cnt-- > info->ra_cnt)
			cmd_rotate_b(b, cmd);
	}
}

static void	rbrra(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	while (info->rb_cnt-- > 0)
		cmd_rotate_b(b, cmd);
	while (info->rra_cnt-- > 0)
		cmd_reverse_rotate_a(a, cmd);
}

static void	rrbra(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	while (info->rrb_cnt-- > 0)
		cmd_reverse_rotate_b(b, cmd);
	while (info->ra_cnt-- > 0)
		cmd_rotate_a(a, cmd);
}

static void	rrbrra(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	int	rrr_cnt;

	if (info->rra_cnt >= info->rrb_cnt)
	{
		rrr_cnt = info->rrb_cnt;
		while (rrr_cnt-- > 0)
			cmd_reverse_rotate_all(a, b, cmd);
		while (info->rra_cnt-- > info->rrb_cnt)
			cmd_reverse_rotate_a(a, cmd);
	}
	else
	{
		rrr_cnt = info->rra_cnt;
		while (rrr_cnt-- > 0)
			cmd_reverse_rotate_all(a, b, cmd);
		while (info->rrb_cnt-- > info->rra_cnt)
			cmd_reverse_rotate_b(b, cmd);
	}
}

void	move_node(t_rstack *a, t_rstack *b, t_dist_info *info, t_vector *cmd)
{
	if (info->path == RBRA)
		rbra(a, b, info, cmd);
	else if (info->path == RBRRA)
		rbrra(a, b, info, cmd);
	else if (info->path == RRBRA)
		rrbra(a, b, info, cmd);
	else if (info->path == RRBRRA)
		rrbrra(a, b, info, cmd);
	cmd_push_to_a(b, a, cmd);
}
