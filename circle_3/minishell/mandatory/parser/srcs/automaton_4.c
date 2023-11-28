/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:42:43 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:22:53 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "automaton.h"

static void	reduce_one_element(t_automaton *atm, int target)
{
	t_token	token;
	t_node	*left;
	t_node	*root;

	token_constructor(&token, target, NULL);
	stack_node_top(&(atm->st_node), &left);
	stack_node_pop(&(atm->st_node));
	root = (t_node *)malloc(sizeof(t_node));
	node_constructor(root, &token, left, NULL);
	token_destructor(&token);
	stack_node_push(&(atm->st_node), root);
	astree_destructor(root);
}

static void	reduce_two_element(t_automaton *atm, int target)
{
	t_token	token;
	t_node	*right;
	t_node	*left;
	t_node	*root;

	token_constructor(&token, target, NULL);
	stack_node_top(&(atm->st_node), &right);
	stack_node_pop(&(atm->st_node));
	stack_node_top(&(atm->st_node), &left);
	stack_node_pop(&(atm->st_node));
	root = (t_node *)malloc(sizeof(t_node));
	node_constructor(root, &token, left, right);
	token_destructor(&token);
	stack_node_push(&(atm->st_node), root);
	astree_destructor(root);
}

static void	reduce_pseq_element(t_automaton *atm, int target)
{
	t_token	token;
	t_node	*right;
	t_node	*left;
	t_node	*left_left;
	t_node	*root;

	token_constructor(&token, target, NULL);
	stack_node_top(&(atm->st_node), &right);
	stack_node_pop(&(atm->st_node));
	stack_node_top(&(atm->st_node), &left);
	stack_node_pop(&(atm->st_node));
	stack_node_top(&(atm->st_node), &left_left);
	stack_node_pop(&(atm->st_node));
	left->left = left_left;
	root = (t_node *)malloc(sizeof(t_node));
	node_constructor(root, &token, left, right);
	token_destructor(&token);
	stack_node_push(&(atm->st_node), root);
	astree_destructor(root);
}

static void	reduce_scmd_element(t_automaton *atm, int target)
{
	t_token	token;
	t_node	*right_right;
	t_node	*right;
	t_node	*left;
	t_node	*root;

	token_constructor(&token, target, NULL);
	stack_node_top(&(atm->st_node), &right_right);
	stack_node_pop(&(atm->st_node));
	stack_node_top(&(atm->st_node), &right);
	stack_node_pop(&(atm->st_node));
	stack_node_top(&(atm->st_node), &left);
	stack_node_pop(&(atm->st_node));
	right->right = right_right;
	root = (t_node *)malloc(sizeof(t_node));
	node_constructor(root, &token, left, right);
	token_destructor(&token);
	stack_node_push(&(atm->st_node), root);
	astree_destructor(root);
}

void	automaton_reduce(t_automaton *atm, const int *cmd)
{
	if (cmd[4] == 1)
		reduce_one_element(atm, cmd[5]);
	else if (cmd[4] == 2)
		reduce_two_element(atm, cmd[5]);
	else if (cmd[4] == 3)
	{
		if (cmd[5] == PIPE_SEQUENCE)
			reduce_pseq_element(atm, cmd[5]);
		else if (cmd[5] == SIMPLE_COMMAND)
			reduce_scmd_element(atm, cmd[5]);
	}
	stack_int_pop(&(atm->st_state));
	atm->is_enter = FALSE;
}
