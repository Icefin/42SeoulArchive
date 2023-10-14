/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:54 by geshin            #+#    #+#             */
/*   Updated: 2023/10/14 16:02:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

#include "rstack.h"
#include "vector.h"

typedef enum e_path
{
	RBRA = 0,
	RBRRA = 1,
	RRBRA = 2,
	RRBRRA = 3
}	t_path;

typedef struct s_dist_info
{
	int		idx;
	t_node	*node;

	int		ra_cnt;
	int		rra_cnt;

	int		rb_cnt;
	int		rrb_cnt;

	t_path	path;
}	t_dist_info;

void	sort_stack(t_rstack *stack, t_vector *out);
void	process_divide(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd);
void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector* cmd);

#endif

//The smallest number being at the top.
