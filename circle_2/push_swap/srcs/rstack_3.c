/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:31 by geshin            #+#    #+#             */
/*   Updated: 2023/09/27 15:05:32 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstack.h"

void	cmd_swap_top(t_rstack *rstack)
{
	t_node	*temp;

	if (rstack->size <= 1)
		return ;
}

void	cmd_pop_and_push(t_rstack *from, t_rstack *to)
{
	t_node	*temp;
	
	if (from->size == 0)
		return ;
	temp = from->top;
	rstack_pop_top(from);
	rstack_push_top(to, temp);
}

void	cmd_rotate(t_rstack *rstack)
{
	if (rstack->size <= 1)
		return ;
}

void	cmd_reverse_rotate(t_rstack *rstack)
{
	if (rstack->size <= 1)
		return ;
}