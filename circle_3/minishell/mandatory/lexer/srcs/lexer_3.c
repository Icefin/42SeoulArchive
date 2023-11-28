/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:26:43 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 01:37:20 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "lexer.h"

static int	classify_operator_token_type(char *cmd, int idx, t_string *out)
{
	if (cmd[idx] == '<')
	{
		if (cmd[idx + 1] == '<')
		{
			string_constructor(out, "<<");
			return (DLESS);
		}
		string_constructor(out, "<");
		return (SLESS);
	}
	else if (cmd[idx] == '>')
	{
		if (cmd[idx + 1] == '>')
		{
			string_constructor(out, ">>");
			return (DGREAT);
		}
		string_constructor(out, ">");
		return (SGREAT);
	}
	string_constructor(out, "|");
	return (PIPE);
}

void	sp_op_tk(char *cmd, t_vector_token *out, int *i)
{
	t_token		token;
	t_string	data;
	int			type;

	type = classify_operator_token_type(cmd, *i, &data);
	*i = *i + data.length - 1;
	token_constructor(&token, type, &data);
	vector_token_push_back(out, &token);
	token_destructor(&token);
	string_destructor(&data);
}
