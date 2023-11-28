/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:33:44 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:21:07 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "astree.h"
#include "commontype.h"

void	node_constructor(t_node *out, t_token *token, t_node *l, t_node *r)
{
	token_constructor(&(out->token), token->type, &(token->data));
	out->left = l;
	out->right = r;
}

void	node_destructor(t_node *node)
{
	token_destructor(&(node->token));
}

t_node	*astree_copy(t_node *og)
{
	t_node	*node;
	t_node	*left;
	t_node	*right;

	if (og == NULL)
		return (NULL);
	node = (t_node *)malloc(sizeof(t_node));
	left = astree_copy(og->left);
	right = astree_copy(og->right);
	token_constructor(&(node->token), og->token.type, &(og->token.data));
	node->left = left;
	node->right = right;
	return (node);
}

void	astree_destructor(t_node *root)
{
	if (root == NULL)
		return ;
	astree_destructor(root->left);
	astree_destructor(root->right);
	node_destructor(root);
	free(root);
}
