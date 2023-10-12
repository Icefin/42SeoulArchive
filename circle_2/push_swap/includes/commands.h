/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:28:12 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 16:21:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//command lists
/*
sa (swap a)			   - Swap the first 2 elements at the top of the stack a. Do nothing if there is only one or no elements.
sb (swap b) 		   - Swap the first 2 elements at the top of the stack b. Do nothing if there is only one or no elements.
ss 					   - sa and sb at the same time.
pa (push a) 		   - Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b) 		   - Take the first element at the top of a and put it at the top of b. Do nohting if a is empty.
ra (rotate a) 		   - Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b) 		   - Shift up all elements of stack b by 1. The first element becomes the last one.
rr			  		   - ra and rb at the same time.
rra (reverse rotate a) - Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b) - Shift down all elements of stack b by 1. The last element becomes the first one.
rrr					   - rra and rrb at the same time.
*/

#ifndef COMMANDS_H
# define COMMANDS_H

#include "rstack.h"
#include "vector.h"

enum e_commands 
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10,

	END = -1
};

void	cmd_swap_top_a(t_rstack *rstack, t_vector *cmd);
void	cmd_push_to_a(t_rstack *from, t_rstack *to, t_vector *cmd);
void	cmd_rotate_a(t_rstack *rstack, t_vector *cmd);
void	cmd_reverse_rotate_a(t_rstack *rstack, t_vector *cmd);

void	cmd_swap_top_b(t_rstack *rstack, t_vector *cmd);
void	cmd_push_to_b(t_rstack *from, t_rstack *to, t_vector *cmd);
void	cmd_rotate_b(t_rstack *rstack, t_vector *cmd);
void	cmd_reverse_rotate_b(t_rstack *rstack, t_vector *cmd);

#endif