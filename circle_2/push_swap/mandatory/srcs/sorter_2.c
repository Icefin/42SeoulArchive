/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:17:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 13:37:55 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	stay_a_stack(t_rstack *stack, t_vector *cmd)
{
	cmd_rotate_a(stack, cmd);
}

static void	to_b_stack_upper(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_push_to_b(a, b, cmd);
}

static void	to_b_stack_lower(t_rstack *a, t_rstack *b, t_vector *cmd)
{
	cmd_push_to_b(a, b, cmd);
	cmd_rotate_b(b, cmd);
}

void	process_divide(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd)
{
	int	pivot_1;
	int	pivot_2;
	int	cnt;

	pivot_1 = (a_stack->size / 3) - 1;
	pivot_2 = 2 * pivot_1;
	cnt = a_stack->size;
	while (cnt > 5)
	{
		if (a_stack->top->value > pivot_2)
			stay_a_stack(a_stack, cmd);
		else if (a_stack->top->value >= pivot_1)
			to_b_stack_upper(a_stack, b_stack, cmd);
		else
			to_b_stack_lower(a_stack, b_stack, cmd);
		cnt--;
	}
	cnt = a_stack->size;
	while (cnt > 3)
	{
		to_b_stack_upper(a_stack, b_stack, cmd);
		cnt--;
	}
}
