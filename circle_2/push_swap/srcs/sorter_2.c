/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:17:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/12 14:44:04 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static void	stay_a_stack()
{

}

static void	to_b_stack_upper()
{

}

static void	to_b_stack_lower()
{
	
}

void	process_divide(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd)
{
	int	pivot_1;
	int	pivot_2;
	int	cnt;

	pivot_1 = a_stack->size / 3;
	pivot_2 = 2 * pivot_1;
	cnt = a_stack->size;
	while (cnt-- > 0)
	{
		if (a_stack->top->value > pivot_2)
			stay_a_stack();
		else if (a_stack->top->value >= pivot_1)
			to_b_stack_upper();
		else
			to_b_stack_lower();
	}
	cnt = a_stack->size - 3;
	while (cnt-- > 0);
		to_b_stack_upper();
	//sort a stack size three
}
