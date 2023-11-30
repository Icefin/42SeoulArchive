/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:19:55 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:23:06 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "commontype.h"
#include "automaton.h"
#include "parser.h"

void	parser_build_astree(t_vector_token *v, t_node **out)
{
	t_automaton	atm;

	automaton_constructor(&atm);
	automaton_process(&atm, v);
	automaton_get_result(&atm, out);
	automaton_destructor(&atm);
}
