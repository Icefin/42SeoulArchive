/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:26:40 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 01:38:07 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "lexer.h"

extern void	expand_parameter(t_map_env *menv, t_string *out);

void	sp_wd_tk(char *cmd, t_map_env *menv, t_vector_token *out, int *i)
{
	t_token		token;
	t_string	data;
	int			idx;

	string_constructor(&data, "");
	idx = *i - 1;
	while (cmd[++idx] != '\0')
	{
		if (cmd[idx] == ' '
			|| cmd[idx] == '<'
			|| cmd[idx] == '>'
			|| cmd[idx] == '|')
			break ;
		string_append_char(&data, cmd[idx]);
	}
	*i = idx - 1;
	expand_parameter(menv, &data);
	token_constructor(&token, WORD, &data);
	vector_token_push_back(out, &token);
	token_destructor(&token);
	string_destructor(&data);
}
