/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ast_node.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:19:44 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 16:50:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TOKEN_H
# define STACK_TOKEN_H

# include "astree.h"

typedef struct s_stack_ast_node
{
	t_token	**data;
	int		size;
	int		capacity;
}	t_stack_ast_node;

t_stack_ast_node	*stack_ast_node_constructor(int size);
void				stack_ast_node_destructor(t_stack_ast_node *st);

void				stack_ast_node_push(t_stack_ast_node *st, t_ast_node t);
void				stack_ast_node_pop(t_stack_ast_node *st);

t_ast_node			*stack_ast_node_get_top(t_stack_ast_node *st);
int					stack_ast_node_is_empty(t_stack_ast_node *st);

#endif