/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:30:51 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 07:21:36 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "lexer.h"

#include <stdio.h>

extern void	sp_sq_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *i);
extern void	sp_dq_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *i);
extern void	sp_op_tk(char *cmd, t_vector_token *out, int *i);
extern void	sp_wd_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *i);

void	lexer_tokenize_command(char *cmd, t_map_env *menv, t_vector_token *out)
{
	t_token	token;
	int		idx;

	idx = -1;
	while (cmd[++idx] != '\0')
	{
		if (cmd[idx] == '\'')
			sp_sq_tk(cmd, menv, out, &idx);
		else if (cmd[idx] == '\"')
			sp_dq_tk(cmd, menv, out, &idx);
		else if (cmd[idx] == '<' || cmd[idx] == '>' || cmd[idx] == '|')
			sp_op_tk(cmd, out, &idx);
		else if (cmd[idx] != ' ')
			sp_wd_tk(cmd, menv, out, &idx);
	}
	token_constructor(&token, END, NULL);
	vector_token_push_back(out, &token);
	token_destructor(&token);
}
