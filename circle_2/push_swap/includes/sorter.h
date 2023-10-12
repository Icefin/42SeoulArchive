/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:54 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 14:04:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

#include "rstack.h"
#include "vector.h"

void	sort_stack(t_rstack *stack, t_vector *out);
void	process_divide(t_rstack *a_stack, t_rstack *b_stack, t_vector *cmd);
void	process_merge(t_rstack *a_stack, t_rstack *b_stack, t_vector* cmd);

#endif

//The smallest number being at the top.
