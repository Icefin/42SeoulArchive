/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:30:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 07:05:43 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "commontype.h"
# include "astree.h"

typedef struct s_stack
{
	void	*data;
	int		size;
	int		capacity;
}	t_stack;

void	stack_int_constructor(t_stack *out, int capacity);
void	stack_node_constructor(t_stack *out, int capacity);

void	stack_int_destructor(t_stack *st);
void	stack_node_destructor(t_stack *st);

t_bool	stack_is_empty(t_stack *st);

void	stack_node_push(t_stack *st, t_node *node);
void	stack_node_pop(t_stack *st);
void	stack_node_top(t_stack *st, t_node **out);

void	stack_int_push(t_stack *st, int i);
void	stack_int_pop(t_stack *st);
int		stack_int_top(t_stack *st);

#endif