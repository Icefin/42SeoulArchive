/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:45:27 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:19:17 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
#include "commontype.h"
#include "utils.h"

static void	print_export(t_map_env *menv)
{
	char	*key;
	char	*value;
	char	*str;
	int		idx;

	idx = -1;
	while (++idx < menv->key.size)
	{
		key = get_string_c_str(&(menv->key.data[idx]));
		value = get_string_c_str(&(menv->value.data[idx]));
		if (*value != '\0')
		{
			str = ft_strjoin_with_char(key, value, '=');
			printf("declare -x %s\n", str);
			free(str);
		}
		else
			printf("declare -x %s\n", key);
		free(key);
		free(value);
	}
}

static void	export_insert_environment(t_map_env *menv, char *str)
{
	char		*equal;
	char		*sub;
	t_string	key;
	t_string	value;

	equal = ft_strchr(str, '=');
	if (equal == NULL)
	{
		string_constructor(&key, str);
		string_constructor(&value, "");
	}
	else
	{
		sub = ft_substr(str, 0, equal - str);
		string_constructor(&key, sub);
		free(sub);
		string_constructor(&value, equal + 1);
	}
	if ((map_environment_find_index(menv, &key) > 0 && equal == NULL) == FALSE)
		map_environment_insert(menv, &key, &value);
	string_destructor(&key);
	string_destructor(&value);
}

int	execute_export(t_command *cmd, t_map_env *menv)
{
	int		idx;

	if (cmd->argc == 1)
		print_export(menv);
	idx = 0;
	while (++idx < cmd->argc)
		export_insert_environment(menv, cmd->argv[idx]);
	return (0);
}

int	execute_exit(void)
{
	exit(0);
}
