/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:12:15 by geshin            #+#    #+#             */
/*   Updated: 2023/09/19 18:48:00 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSTACK_H
# define RSTACK_H

#include <stdlib.h>

#include <stdio.h>

typedef struct s_node
{
	int		value;
	t_node	*next;
	t_node	*prev;	
}	t_node;

t_node	*init_node(int value, t_node *next, t_node *prev);
void	destroy_node(t_node *node);

typedef struct s_rstack
{
	int		size;
	t_node	*bottom;
	t_node	*top;
}	t_rstack;

void	init_rstack(t_rstack *rstack);
void	destroy_rstack(t_rstack *rstack);

void	rstack_push_top(t_rstack *rstack, t_node *node);
void	rstack_pop_top(t_rstack *rstack);
void	rstack_push_bottom(t_rstack *rstack, t_node *node);
void	rstack_pop_bottom(t_rstack *rstack);

void	cmd_swap_top(t_rstack *rstack);
void	cmd_pop_and_push(t_rstack *from, t_rstack *to);
void	cmd_rotate(t_rstack *rstack);
void	cmd_reverse_rotate(t_rstack *rstack);

//command lists
/*
sa (swap a) 		   - Swap the first 2 elements at the top of the stack a. Do nothing if there is only one or no elements.
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

#endif