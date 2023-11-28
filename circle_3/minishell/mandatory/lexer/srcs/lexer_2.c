/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:48:56 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 01:43:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "lexer.h"

extern void	expand_parameter(t_map_env *menv, t_string *out);

static t_bool	is_closed_expression(char *cmd, int idx, char delimiter)
{
	while (cmd[++idx] != '\0')
	{
		if (cmd[idx] == delimiter)
			return (TRUE);
	}
	return (FALSE);
}

void	sp_sq_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *i)
{
	t_token		token;
	t_string	data;

	string_constructor(&data, "");
	if (is_closed_expression(cmd, *i, '\'') == TRUE)
	{
		while (cmd[++(*i)] != '\'')
			string_append_char(&data, cmd[*i]);
	}
	else
	{
		*i = (*i) + 1;
		while (cmd[*i] != '\0' && cmd[*i] != ' ')
		{
			string_append_char(&data, cmd[*i]);
			*i = (*i) + 1;
		}
		expand_parameter(menv, &data);
	}
	token_constructor(&token, WORD, &data);
	vector_token_push_back(out, &token);
	token_destructor(&token);
	string_destructor(&data);
}

void	sp_dq_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *idx)
{
	t_token		token;
	t_string	data;

	string_constructor(&data, "");
	if (is_closed_expression(cmd, *idx, '\"') == TRUE)
	{
		while (cmd[++(*idx)] != '\"')
			string_append_char(&data, cmd[*idx]);
	}
	else
	{
		*idx = (*idx) + 1;
		while (cmd[*idx] != '\0' && cmd[*idx] != ' ')
		{
			string_append_char(&data, cmd[*idx]);
			*idx = (*idx) + 1;
		}
	}
	expand_parameter(menv, &data);
	token_constructor(&token, WORD, &data);
	vector_token_push_back(out, &token);
	token_destructor(&token);
	string_destructor(&data);
}
