/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:33:36 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 01:54:34 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "utils.h"

extern char	*get_cwd_without_env(void);
extern char	*get_cwd(t_map_env *menv);

int	execute_unset(t_command *cmd, t_map_env *menv)
{
	int			idx;
	t_string	key;

	if (cmd->argc == 1)
		return (0);
	idx = 0;
	while (++idx < cmd->argc)
	{
		string_constructor(&key, cmd->argv[idx]);
		map_environment_erase(menv, &key);
		string_destructor(&key);
	}
	return (0);
}

void	set_env(t_map_env *menv, char *c_key, char *c_value)
{
	t_string	key;
	t_string	value;

	string_constructor(&key, c_key);
	string_constructor(&value, c_value);
	map_environment_insert(menv, &key, &value);
	string_destructor(&key);
	string_destructor(&value);
}

int	cd_chdir_path(t_map_env *menv, char *path)
{
	char		*oldpwd;
	char		*cwd;

	oldpwd = get_cwd(menv);
	if (chdir(path) == -1)
	{
		free(oldpwd);
		perror("ms: cd ");
		return (1);
	}
	cwd = get_cwd_without_env();
	set_env(menv, "OLDPWD", oldpwd);
	set_env(menv, "PWD", cwd);
	free(oldpwd);
	free(cwd);
	return (0);
}

static int	cd_go_home(t_map_env *menv)
{
	int			idx;
	char		*path;
	t_string	key;

	string_constructor(&key, "HOME");
	idx = map_environment_find_index(menv, &key);
	string_destructor(&key);
	if (idx < 0)
	{
		perror("cd: HOME not set");
		return (1);
	}
	path = get_string_c_str(&(menv->value.data[idx]));
	cd_chdir_path(menv, path);
	free(path);
	return (0);
}

int	execute_cd(t_command *cmd, t_map_env *menv)
{
	char	*cur_path;
	char	*tmp;
	int		status;

	status = 0;
	if (cmd->argc == 1)
		return (cd_go_home(menv));
	if (ft_strncmp(cmd->argv[1], ".", 1) == 0 \
		|| ft_strncmp(cmd->argv[1], "..", 2) == 0 \
		|| ft_strncmp(cmd->argv[1], "/", 1) == 0)
		status = cd_chdir_path(menv, cmd->argv[1]);
	else
	{
		tmp = get_cwd(menv);
		cur_path = ft_strjoin_with_char(tmp, cmd->argv[1], '/');
		free(tmp);
		status = cd_chdir_path(menv, cur_path);
		free(cur_path);
	}
	return (status);
}
