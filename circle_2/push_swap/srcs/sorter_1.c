/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:15:50 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 01:17:28 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static int	get_optimal_chunk_size(int size)
{
	return ((0.000000053 * size * size) + (0.03 * size) +14.5);
}

void	sort_stack(t_rstack *stack, t_vector *out)
{
	int	chunk;

	chunk = get_optimal_chunk_size(stack->size);
}