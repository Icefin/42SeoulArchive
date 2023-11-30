/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:37:27 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 11:23:22 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "lexer.h"

extern int	g_errno;

static void	expand_exit_status(int *idx, t_string *out)
{
	if (g_errno >= 100)
	{
		string_append_char(out, '1');
		string_append_char(out, '0' + ((g_errno - 100) / 10));
		string_append_char(out, '0' + (g_errno % 10));
	}
	else if (g_errno >= 10)
	{
		string_append_char(out, '0' + (g_errno / 10));
		string_append_char(out, '0' + (g_errno % 10));
	}
	else
		string_append_char(out, '0' + (g_errno % 10));
	*idx = *idx + 1;
}

static t_bool	is_op_tk(char c)
{
	if (c == '\0' || c == ' ' || c == '='
		|| c == '<' || c == '>' || c == '|' || c == '$')
		return (TRUE);
	return (FALSE);
}

static void	expand_env(t_map_env *menv, t_string *str, int *idx, t_string *out)
{
	t_string	key;
	int			i;
	int			val_idx;

	string_constructor(&key, "");
	i = *idx;
	while (++i < str->length)
	{
		if (is_op_tk(str->str[i]) == TRUE)
			break ;
		string_append_char(&key, str->str[i]);
		val_idx = map_environment_find_index(menv, &key);
		if (val_idx != -1)
			break ;
	}
	if (is_op_tk(str->str[i]) == TRUE)
		i--;
	*idx = i;
	if (val_idx == -1)
	{
		string_destructor(&key);
		return ;
	}
	string_append_string(out, &(menv->value.data[val_idx]));
	string_destructor(&key);
}

void	expand_parameter(t_map_env *menv, t_string *out)
{
	t_string	xout;
	char		*tmp;
	int			i;

	string_constructor(&xout, "");
	i = -1;
	while (++i < out->length)
	{
		if (out->str[i] == '$')
		{
			if (i < out->length - 1 && out->str[i + 1] == '?')
				expand_exit_status(&i, &xout);
			else
				expand_env(menv, out, &i, &xout);
		}
		else
			string_append_char(&xout, out->str[i]);
	}
	string_destructor(out);
	tmp = get_string_c_str(&xout);
	string_constructor(out, tmp);
	string_destructor(&xout);
	free(tmp);
}
