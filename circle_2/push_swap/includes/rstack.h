/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:12:15 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 16:09:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSTACK_H
# define RSTACK_H

#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;	
}	t_node;

t_node	*create_node(int value, t_node *next, t_node *prev);
void	destroy_node(t_node *node);

typedef struct s_rstack
{
	int		size;
	t_node	*bottom;
	t_node	*top;
}	t_rstack;

void	init_rstack(t_rstack *rstack);
void	destroy_rstack(t_rstack *rstack);

void	rstack_push_top(t_rstack *rstack, int val);
void	rstack_pop_top(t_rstack *rstack);
void	rstack_push_bottom(t_rstack *rstack, int val);
void	rstack_pop_bottom(t_rstack *rstack);

#endif