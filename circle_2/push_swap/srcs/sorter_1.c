/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:15:50 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 15:16:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

#include <stdio.h>

static void	sort_size_two(t_rstack *stack, t_vector *cmd)
{
	if (stack->top->value < stack->bottom->value)
		return ;
	cmd_swap_top(stack);
	vector_push_back(cmd, SA);
}

static void	sort_size_three(t_rstack *stack, t_vector *cmd)
{
	//sort size three stack with optimal command number
}

static void	process_small_size(t_rstack *stack, t_vector *cmd)
{
	if (stack->size == 2)
		sort_size_two(stack, cmd);
	else if (stack->size == 3)
		sort_size_three(stack, cmd);
}

void	sort_stack(t_rstack *stack, t_vector *out)
{
	t_rstack	b_stack;

	if (stack->size <= 3)
	{
		process_small_size(stack, out);
		return;
	}
	init_rstack(&b_stack);
	process_divide(stack, &b_stack, out);
	process_merge(stack, &b_stack, out);
}