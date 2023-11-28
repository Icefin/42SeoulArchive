/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:05:12 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:01:22 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H

# include "token.h"

typedef struct s_node
{
	t_token			token;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

void	node_constructor(t_node *out, t_token *token, t_node *l, t_node *r);
void	node_destructor(t_node *node);

t_node	*astree_copy(t_node *origin);

void	astree_destructor(t_node *root);

#endif