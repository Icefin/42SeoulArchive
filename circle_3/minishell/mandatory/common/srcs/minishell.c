/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:38:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 11:52:21 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "commontype.h"
#include "map_environment.h"
#include "utils.h"
#include "lexer.h"
#include "parser.h"
#include "astree.h"
#include "interpreter.h"

int	g_errno;

static void display_shell_title(void)
{
	system("clear");
	printf("\033[0;32m");
	printf("====================================================================================\n");
	printf("_______  ______    _______  _______    _______  __   __  _______  ___      ___\n");
	printf("|       ||    _ |  |       ||       |  |       ||  | |  ||       ||   |    |   |\n");
	printf("|_     _||   | ||  |    ___||    ___|  |  _____||  |_|  ||    ___||   |    |   |\n");
	printf("  |   |  |   |_||_ |   |___ |   |___   | |_____ |       ||   |___ |   |    |   |\n");
	printf("  |   |  |    __  ||    ___||    ___|  |_____  ||       ||    ___||   |___ |   |___ \n");
	printf("  |   |  |   |  | ||   |___ |   |___    _____| ||   _   ||   |___ |       ||       |\n");
	printf("  |___|  |___|  |_||_______||_______|  |_______||__| |__||_______||_______||_______|\n");
	printf("                                                         Author : jihwjeon, geshin  \n");
	printf("====================================================================================\n\n");
	printf("\033[0m");
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint_handler);
}

static void	init_shell(t_map_env *menv, char **envp, int argc, char **argv)
{
	int			size;
	char		*tmp;
	char		*sub;
	t_string	key;
	t_string	value;

	size = -1;
	while (envp[++size] != NULL)
		;
	map_environment_constructor(menv, size);
	size = -1;
	while (envp[++size] != NULL)
	{
		tmp = ft_strchr(envp[size], '=');
		sub = ft_substr(envp[size], 0, tmp - envp[size]);
		string_constructor(&key, sub);
		free(sub);
		string_constructor(&value, tmp + 1);
		map_environment_insert(menv, &key, &value);
		string_destructor(&key);
		string_destructor(&value);
	}
	(void)argc;
	(void)argv;
	init_signal();
}

static int	input_command(char **command)
{
	while (TRUE)
	{
		*command = readline("\033[1;32m TreeShell seed % \033[0m");
		if (*command == NULL)
			return (FALSE);
		if (*command[0] == '\0')
		{
			free(*command);
			continue ;
		}
		add_history(*command);
		return (TRUE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*command;
	t_map_env		menv;
	t_vector_token	vtoken;
	t_node			*root;

	init_shell(&menv, envp, argc, argv);
	display_shell_title();
	while (TRUE)
	{
		if (input_command(&command) == FALSE)
			break ;
		vector_token_constructor(&vtoken, 10);
		lexer_tokenize_command(command, &menv, &vtoken);
		free(command);
		parser_build_astree(&vtoken, &root);
		vector_token_destructor(&vtoken);
		if (root == NULL)
		{
			printf("Parse Error : Invalid Syntax\n");
			continue ;
		}
		g_errno = execute_ast(root, &menv);
		astree_destructor(root);
	}
	map_environment_destructor(&menv);
	return (0);
}
