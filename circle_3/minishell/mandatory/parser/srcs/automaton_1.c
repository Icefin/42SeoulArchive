/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:42:24 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:06:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automaton.h"

void	automaton_constructor(t_automaton *out)
{
	stack_node_constructor(&(out->st_node), 64);
	stack_int_constructor(&(out->st_state), 64);
	stack_int_push(&(out->st_state), STATE_0);
	out->is_enter = TRUE;
}

void	automaton_destructor(t_automaton *atm)
{
	stack_node_destructor(&(atm->st_node));
	stack_int_destructor(&(atm->st_state));
}
