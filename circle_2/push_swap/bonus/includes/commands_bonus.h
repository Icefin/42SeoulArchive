/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:17:52 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 13:40:38 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_BONUS_H
# define COMMANDS_BONUS_H

# include "rstack_bonus.h"

void	cmd_swap_top_a_bonus(t_rstack *stack);
void	cmd_swap_top_b_bonus(t_rstack *stack);
void	cmd_swap_top_all_bonus(t_rstack *a, t_rstack *b);
void	cmd_push_to_a_bonus(t_rstack *from, t_rstack *to);
void	cmd_push_to_b_bonus(t_rstack *from, t_rstack *to);

void	cmd_rotate_a_bonus(t_rstack *stack);
void	cmd_rotate_b_bonus(t_rstack *stack);
void	cmd_rotate_all_bonus(t_rstack *a, t_rstack *b);

void	cmd_reverse_rotate_a_bonus(t_rstack *stack);
void	cmd_reverse_rotate_b_bonus(t_rstack *stack);
void	cmd_reverse_rotate_all_bonus(t_rstack *a, t_rstack *b);

#endif