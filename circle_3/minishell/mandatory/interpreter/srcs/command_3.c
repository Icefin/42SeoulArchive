/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:28:53 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/30 14:33:00 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "map_environment.h"
#include "string.h"
#include "utils.h"

extern void	command_exit(t_command *cmd, t_map_env *menv);
extern void	init_signal(void);
extern void	ft_free_char_arr(char **arr);

char	**get_splitted_path(t_map_env *menv)
{
	char		**splitted;
	char		*path;
	t_string	key;
	int			idx;

	string_constructor(&key, "PATH");
	idx = map_environment_find_index(menv, &key);
	string_destructor(&key);
	if (idx < 0)
		return (NULL);
	path = get_string_c_str(&(menv->value.data[idx]));
	splitted = ft_split(path, ':');
	free(path);
	return (splitted);
}

char	*attatch_path_to_command(char *cmd, char **splitted_path)
{
	int		idx;
	char	*full_path;

	if (splitted_path == NULL)
		return (ft_strdup(cmd));
	idx = -1;
	while (splitted_path[++idx] != NULL)
	{
		full_path = ft_strjoin_with_char(splitted_path[idx], cmd, '/');
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (ft_strdup(cmd));
}

char	**map_environment_convert_to_char(t_map_env *menv)
{
	int		idx;
	char	**envp;
	char	*key;
	char	*value;

	envp = (char **)malloc(sizeof(char *) * (menv->key.size + 1));
	idx = -1;
	while (++idx < menv->key.size)
	{
		key = get_string_c_str(&(menv->key.data[idx]));
		value = get_string_c_str(&(menv->value.data[idx]));
		envp[idx] = ft_strjoin_with_char(key, value, '=');
		free(key);
		free(value);
	}
	envp[idx] = NULL;
	return (envp);
}

void	execute_child_binary(t_command *cmd, t_map_env *menv)
{
	char	**splitted;
	char	*full_path_cmd;
	char	**envp;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	splitted = get_splitted_path(menv);
	full_path_cmd = attatch_path_to_command(cmd->argv[0], splitted);
	envp = map_environment_convert_to_char(menv);
	if (execve(full_path_cmd, cmd->argv, envp) == -1)
	{
		ft_free_char_arr(splitted);
		ft_free_char_arr(envp);
		free(full_path_cmd);
		perror(cmd->argv[0]);
		command_exit(cmd, menv);
	}
}

int	execute_binary(t_command *cmd, t_map_env *menv)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
		execute_child_binary(cmd, menv);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) != 0)
	{
		if (WTERMSIG(status) == SIGINT)
			printf("\n");
		else if (WTERMSIG(status) == SIGQUIT)
			printf("Quit: %d\n", status);
		status += 128;
	}
	init_signal();
	return (WEXITSTATUS(status));
}
