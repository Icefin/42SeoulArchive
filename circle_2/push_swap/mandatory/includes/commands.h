/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:28:12 by geshin            #+#    #+#             */
/*   Updated: 2023/10/23 13:30:05 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "rstack.h"
# include "vector.h"

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

void	cmd_swap_top_a(t_rstack *stack, t_vector *cmd);
void	cmd_swap_top_b(t_rstack *stack, t_vector *cmd);
void	cmd_swap_top_all(t_rstack *a, t_rstack *b, t_vector *cmd);
void	cmd_push_to_a(t_rstack *from, t_rstack *to, t_vector *cmd);
void	cmd_push_to_b(t_rstack *from, t_rstack *to, t_vector *cmd);

void	cmd_rotate_a(t_rstack *stack, t_vector *cmd);
void	cmd_rotate_b(t_rstack *stack, t_vector *cmd);
void	cmd_rotate_all(t_rstack *a, t_rstack *b, t_vector *cmd);

void	cmd_reverse_rotate_a(t_rstack *stack, t_vector *cmd);
void	cmd_reverse_rotate_b(t_rstack *stack, t_vector *cmd);
void	cmd_reverse_rotate_all(t_rstack *a, t_rstack *b, t_vector *cmd);

#endif