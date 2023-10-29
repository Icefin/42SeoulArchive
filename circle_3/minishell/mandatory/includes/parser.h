/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/30 03:46:24 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stack_ast_node.h"
# include "queue_token.h"

typedef enum e_action
{
	NONE = -1,
	SHIFT,
	REDUCE,
	ACCEPT
}	t_action;

typedef struct s_parser
{
	t_stack_ast_node	stack;
	int					**ptable;
	int					state;
}	t_parser;

/*
** Build ASTree from vector<token>
** Can Build ASTree : return TRUE(1)
** Cannot Build ASTree : return FALSE(0)
*/
int	parser_build_astree(t_queue_token *q, t_ast_node *out);

#endif