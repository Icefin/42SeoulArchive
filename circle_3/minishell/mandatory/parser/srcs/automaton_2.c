/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:42:29 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 07:06:42 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "commontype.h"
#include "automaton.h"

extern void	automaton_shift(t_automaton *atm, t_token *token, int next, int *i);
extern void	automaton_reduce(t_automaton *atm, const int *cmd);
extern void	automaton_goto(t_automaton *atm, int next);
extern void	automaton_accept(t_automaton *atm);

static const int	*get_current_command(t_automaton *atm, t_token *token)
{
	int		i;
	int		atm_state;
	int		node_type;
	t_node	*top;

	node_type = DEFAULT;
	if (stack_is_empty(&(atm->st_node)) == FALSE)
	{
		stack_node_top(&(atm->st_node), &top);
		node_type = top->token.type;
		astree_destructor(top);
	}
	atm_state = stack_int_top((&atm->st_state));
	i = -1;
	while (++i < PTABLE_ROW)
	{
		if (g_ptable[i][0] == atm_state)
		{
			if (atm->is_enter == TRUE
				&& (g_ptable[i][1] == token->type || g_ptable[i][1] == DEFAULT))
				return (g_ptable[i]);
			else if (atm->is_enter == FALSE && g_ptable[i][1] == node_type)
				return (g_ptable[i]);
		}
	}
	return (NULL);
}

//		printf("command : [CS : %d], [TK : %d], [ACT : %d], [NS : %d],
// [PC : %d], [TTK : %d]\n", cmd[0], cmd[1], cmd[2], cmd[3], cmd[4], cmd[5]);
void	automaton_process(t_automaton *atm, t_vector_token *v)
{
	int			i;
	const int	*cmd;

	i = 0;
	while (TRUE)
	{
		if (stack_is_empty(&(atm->st_state)) == TRUE
			|| stack_int_top(&(atm->st_state)) == STATE_25)
			break ;
		cmd = get_current_command(atm, &(v->data[i]));
		if (cmd == NULL)
		{
			stack_int_pop(&(atm->st_state));
			atm->is_enter = FALSE;
			continue ;
		}
		if (cmd[2] == SHIFT)
			automaton_shift(atm, &(v->data[i]), cmd[3], &i);
		else if (cmd[2] == REDUCE)
			automaton_reduce(atm, cmd);
		else if (cmd[2] == GOTO)
			automaton_goto(atm, cmd[3]);
		else if (cmd[2] == ACCEPT)
			automaton_accept(atm);
	}
}

void	automaton_get_result(t_automaton *atm, t_node **out)
{
	int	state;

	if (atm->st_node.size != 1)
	{
		*out = NULL;
		return ;
	}
	state = stack_int_top(&(atm->st_state));
	if (state != STATE_25)
	{
		*out = NULL;
		return ;
	}
	stack_node_top(&(atm->st_node), out);
}
