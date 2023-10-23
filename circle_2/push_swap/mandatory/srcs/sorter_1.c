/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:15:50 by geshin            #+#    #+#             */
/*   Updated: 2023/10/23 13:52:17 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"
#include "commands.h"

static void	sort_size_two(t_rstack *stack, t_vector *cmd)
{
	if (stack->top->value < stack->bottom->value)
		return ;
	cmd_swap_top_a(stack, cmd);
}

static void	sort_size_three(t_rstack *stack, t_vector *cmd)
{
	if (stack->top->prev->value > stack->top->value
		&& stack->top->value > stack->bottom->value)
		cmd_reverse_rotate_a(stack, cmd);
	else if (stack->top->value > stack->bottom->value
		&& stack->bottom->value > stack->top->prev->value)
		cmd_rotate_a(stack, cmd);
	else if (stack->top->prev->value > stack->bottom->value
		&& stack->bottom->value > stack->top->value)
	{
		cmd_reverse_rotate_a(stack, cmd);
		cmd_swap_top_a(stack, cmd);
	}
	else if (stack->bottom->value > stack->top->value
		&& stack->top->value > stack->top->prev->value)
		cmd_swap_top_a(stack, cmd);
	else if (stack->top->value > stack->top->prev->value
		&& stack->top->prev->value > stack->bottom->value)
	{
		cmd_swap_top_a(stack, cmd);
		cmd_reverse_rotate_a(stack, cmd);
	}
}

static void	process_small_size(t_rstack *stack, t_vector *cmd)
{
	if (stack->size == 2)
		sort_size_two(stack, cmd);
	else if (stack->size == 3)
		sort_size_three(stack, cmd);
}

static void	post_process_sort(t_rstack *stack, t_vector *cmd)
{
	t_node	*node;
	int		idx;

	node = stack->top;
	idx = 0;
	while (node->value != 0)
	{
		node = node->prev;
		idx++;
	}
	if (stack->size - idx > idx)
	{
		while (idx-- > 0)
			cmd_rotate_a(stack, cmd);
	}
	else
	{
		while (stack->size - idx > 0)
		{
			cmd_reverse_rotate_a(stack, cmd);
			idx += 1;
		}
	}
	vector_push_back(cmd, END);
}

void	sort_stack(t_rstack *stack, t_vector *out)
{
	t_rstack	b_stack;

	if (stack->size <= 3)
		process_small_size(stack, out);
	else
	{
		init_rstack(&b_stack);
		process_divide(stack, &b_stack, out);
		sort_size_three(stack, out);
		process_merge(stack, &b_stack, out);
	}
	post_process_sort(stack, out);
}
