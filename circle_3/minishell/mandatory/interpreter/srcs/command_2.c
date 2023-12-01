/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:32:04 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/30 13:56:50 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "astree.h"
#include "builtin.h"
#include "command.h"
#include "commontype.h"
#include "redirection.h"
#include "string.h"
#include "utils.h"

extern int	visit_cmd(t_node *n, t_map_env *menv, t_command *cmd, int *res);
extern int	execute_binary(t_command *cmd, t_map_env *menv);

void	command_vargs_to_argv(t_command *out)
{
	int	idx;

	out->argv = (char **)malloc(sizeof(char *) * (out->argc + 1));
	idx = -1;
	while (++idx < out->argc)
		out->argv[idx] = get_string_c_str(&(out->vargs.data[idx]));
	out->argv[idx] = NULL;
}

void	command_exit(t_command *cmd, t_map_env *menv)
{
	command_destructor(cmd);
	map_environment_destructor(menv);
	exit(127);
}

void	ft_free_char_arr(char **arr)
{
	int	idx;

	idx = -1;
	while (arr != NULL && arr[++idx] != NULL)
		free(arr[idx]);
}

int	classify_execution(t_command *cmd, t_map_env *menv)
{
	int	status;

	if (cmd->argc == 0)
		return (0);
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		status = execute_echo(cmd);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		status = execute_cd(cmd, menv);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		status = execute_pwd();
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		status = execute_export(cmd, menv);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		status = execute_unset(cmd, menv);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		status = execute_env(menv);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		status = execute_exit();
	else
		status = execute_binary(cmd, menv);
	return (status);
}

int	execute_cmd(t_node *node, t_map_env *menv, int piperead, int pipewrite)
{
	t_command	cmd;
	int			status;

	status = 0;
	command_constructor(&cmd);
	redirection_pipe(piperead, pipewrite);
	vector_string_constructor(&(cmd.vargs), 10);
	visit_cmd(node, menv, &cmd, &status);
	if (status != 0)
	{
		command_destructor(&cmd);
		return (status);
	}
	command_vargs_to_argv(&cmd);
	status = classify_execution(&cmd, menv);
	command_destructor(&cmd);
	return (status);
}
