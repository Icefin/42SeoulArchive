/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:54 by geshin            #+#    #+#             */
/*   Updated: 2023/10/13 14:56:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

#include "rstack.h"
#include "vector.h"

typedef struct s_dist_info
{
	int		idx;
	t_node	*node;

	int		a_to_upper;
	int		a_to_lower;

	int		b_to_upper;
	int		b_to_lower;
}	t_dist_info;

void	sort_stack(t_rstack *stack, t_vector *out);
void	process_divide(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd);
void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector* cmd);

#endif

//The smallest number being at the top.
