/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:05:12 by geshin            #+#    #+#             */
/*   Updated: 2023/10/28 15:21:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H

# include "token.h"

typedef struct s_ast_node
{
	t_token			*token;
	t_ast_node		*left;
	t_ast_node		*right;
}	t_ast_node;

t_ast_node	*ast_node_constructor();
void		ast_node_destructor();

#endif