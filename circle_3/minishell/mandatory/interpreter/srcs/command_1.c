/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:17:36 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 01:55:07 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "command.h"

void	command_constructor(t_command *out)
{
	out->argc = 0;
	out->argv = NULL;
	out->stdin_fd = dup(STDIN_FD);
	out->stdout_fd = dup(STDOUT_FD);
}

void	command_destructor(t_command *cmd)
{
	int	idx;

	vector_string_destructor(&(cmd->vargs));
	dup2(cmd->stdin_fd, STDIN_FD);
	close(cmd->stdin_fd);
	dup2(cmd->stdout_fd, STDOUT_FD);
	close(cmd->stdout_fd);
	if (cmd->argv == NULL)
		return ;
	idx = -1;
	while (cmd->argv[++idx] != NULL)
		free(cmd->argv[idx]);
	free(cmd->argv);
}
