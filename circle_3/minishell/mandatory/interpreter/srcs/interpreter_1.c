/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:43:17 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/30 14:51:48 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "astree.h"
#include "command.h"
#include "map_environment.h"
#include "redirection.h"

extern int	execute_cmd(t_node *node, t_map_env *menv, int pr, int pw);
extern void	interpreter_exit(t_node *node, t_map_env *menv);
extern int	visit_for_heredoc(t_node *node, t_map_env *menv, int *pipe_cnt);

int	execute_left(t_node *node, t_map_env *menv, int *pipefd)
{
	int		status;
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("ms");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("ms");
		return (1);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		status = execute_cmd(node, menv, STDIN_FD, pipefd[1]);
		exit(status);
	}
	return (0);
}

int	execute_right(t_node *node, t_map_env *menv, int piperead, int *pipefd)
{
	int		status;
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("ms");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("ms");
		return (1);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		status = execute_cmd(node, menv, piperead, pipefd[1]);
		exit(status);
	}
	return (0);
}

int	execute_pipe_sequence(t_node *node, t_map_env *menv, int *pipefd)
{
	int		fd[2];
	int		status;

	status = 0;
	if (node->left->token.type == SIMPLE_COMMAND)
		status = execute_left(node->left, menv, pipefd);
	else if (node->left->token.type == PIPE)
	{
		status = execute_pipe_sequence(node->left->left, menv, fd);
		if (status != 0)
			return (status);
		close(fd[1]);
		status = execute_right(node->right, menv, fd[0], pipefd);
		close(fd[0]);
	}
	return (status);
}

int	execute_pipeline(t_node *node, t_map_env *menv, int pipe_cnt)
{
	int		status;
	int		fd[2];
	pid_t	pid;
	int		idx;

	if (execute_pipe_sequence(node->left->left, menv, fd) != 0)
		interpreter_exit(node, menv);
	close(fd[1]);
	pid = fork();
	if (pid < 0)
		interpreter_exit(node, menv);
	else if (pid == 0)
	{
		status = execute_cmd(node->right, menv, fd[0], STDOUT_FD);
		exit(status);
	}
	close(fd[0]);
	waitpid(pid, &status, 0);
	idx = -1;
	while (++idx < pipe_cnt)
		wait(NULL);
	return (status);
}

void	execute_ast(t_node *root, t_map_env *menv)
{
	int	pipe_cnt;

	menv->exit_status = visit_for_heredoc(root, menv, &pipe_cnt);
	if (menv->exit_status != 0)
		return ;
	if (root->left->token.type == PIPE)
		menv->exit_status = execute_pipeline(root, menv, pipe_cnt);
	else if (root->left->token.type == SIMPLE_COMMAND)
		menv->exit_status = execute_cmd(root->left, menv, STDIN_FD, STDOUT_FD);
}
