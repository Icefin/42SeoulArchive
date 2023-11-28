/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:42:38 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:05:13 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "automaton.h"

void	automaton_shift(t_automaton *atm, t_token *token, int next, int *i)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node_constructor(node, token, NULL, NULL);
	stack_node_push(&(atm->st_node), node);
	astree_destructor(node);
	stack_int_push(&(atm->st_state), next);
	atm->is_enter = TRUE;
	*i = *i + 1;
}
