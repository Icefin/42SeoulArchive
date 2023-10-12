/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/12 14:54:06 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector* cmd)
{
	while (b_stack->size > 0)
	{
		//find greedy elements from b to a
		//move the element to a
		//record all commands to cmd
	}
}