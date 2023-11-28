/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:50:04 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 07:09:46 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "astree.h"
#include "command.h"
#include "map_environment.h"
#include "redirection.h"
#include "string.h"

extern int	g_errno;
extern int	handle_heredoc(t_map_env *menv, t_string *delimeter);

int	visit_io_redirect(t_node *node)
{
	int	status;

	status = 0;
	if (node->token.type == IO_FILE)
	{
		if (node->left->token.type == SLESS)
			status = redirection_in(&(node->right->left->token.data));
		else if (node->left->token.type == SGREAT)
			status = redirection_out(&(node->right->left->token.data));
		else if (node->left->token.type == DGREAT)
			status = redirection_append(&(node->right->left->token.data));
	}
	else if (node->token.type == IO_HERE)
		status = redirection_heredoc(&(node->right->left->token.data));
	return (status);
}

int	visit_cmd(t_node *node, t_map_env *menv, t_command *cmd, int *res)
{
	if (node == NULL)
		return (0);
	else if (node->token.type == IO_REDIRECT)
		return (visit_io_redirect(node->left));
	*res += visit_cmd(node->left, menv, cmd, res);
	*res += visit_cmd(node->right, menv, cmd, res);
	if (node->token.type == WORD)
	{
		vector_string_push_back(&(cmd->vargs), &(node->token.data));
		++(cmd->argc);
	}
	return (0);
}

int	visit_for_heredoc(t_node *node, t_map_env *menv, int *pipe_cnt)
{
	if (node == NULL)
		return (0);
	if (visit_for_heredoc(node->left, menv, pipe_cnt) != 0
		|| visit_for_heredoc(node->right, menv, pipe_cnt) != 0)
		return (1);
	if (node->token.type == PIPE)
		++(*pipe_cnt);
	if (node->token.type == IO_HERE)
		return (handle_heredoc(menv, &(node->right->left->token.data)));
	return (0);
}

void	interpreter_exit(t_node *node, t_map_env *menv)
{
	astree_destructor(node);
	map_environment_destructor(menv);
	exit(errno);
}
