/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:38:08 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:19:07 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "commontype.h"
#include "utils.h"

static t_bool	is_newline_option(char *word)
{
	int	idx;

	if (ft_strlen(word) < 2 || word[0] != '-')
		return (FALSE);
	idx = 0;
	while (word[++idx] != '\0')
	{
		if (word[idx] != 'n')
			return (FALSE);
	}
	return (TRUE);
}

int	execute_echo(t_command *cmd)
{
	int	idx;
	int	newline_flag;

	idx = 0;
	newline_flag = FALSE;
	while (++idx < cmd->argc)
	{
		if (is_newline_option(cmd->argv[idx]) == FALSE)
			break ;
		newline_flag = TRUE;
	}
	while (idx < cmd->argc)
	{
		ft_putstr_fd(cmd->argv[idx], STDOUT_FD);
		if (idx != cmd->argc - 1)
			ft_putstr_fd(" ", STDOUT_FD);
		++idx;
	}
	if (cmd->argc > 1 && newline_flag == FALSE)
		ft_putstr_fd("\n", STDOUT_FD);
	return (0);
}

char	*get_cwd_without_env(void)
{
	int		idx;
	int		size;
	char	*cwd;

	idx = -1;
	size = 1024;
	while (++idx < 3)
	{
		cwd = (char *)malloc(sizeof(char) * size);
		getcwd(cwd, size);
		if (cwd != NULL)
			break ;
		free(cwd);
		size *= 2;
	}
	return (cwd);
}

char	*get_cwd(t_map_env *menv)
{
	char		*cwd;
	int			idx;
	t_string	key;

	string_constructor(&key, "PWD");
	idx = map_environment_find_index(menv, &key);
	string_destructor(&key);
	if (idx > 0)
		cwd = get_string_c_str(&(menv->value.data[idx]));
	else
		cwd = get_cwd_without_env();
	return (cwd);
}

int	execute_pwd(void)
{
	char	*cwd;

	cwd = get_cwd_without_env();
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
