/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:42:48 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 01:11:23 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "automaton.h"

void	automaton_goto(t_automaton *atm, int next)
{
	stack_int_push(&(atm->st_state), next);
	atm->is_enter = TRUE;
}

void	automaton_accept(t_automaton *atm)
{
	stack_int_push(&(atm->st_state), STATE_25);
	atm->is_enter = TRUE;
}
