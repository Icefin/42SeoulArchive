/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:38:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/31 15:22:49 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "lexer.h"
#include "parser.h"

#define	FALSE	0
#define	TRUE	1

int	errno;

static void	init_shell()
{
	return ;
}

int main(int argc, char **argv, char **envp)
{
	char			*command;
	t_queue_token	qtoken;
	t_ast_node		root;

#pragma region SHELL_INIT
	printf("==========INIT SHELL==========\n");
	init_shell();
#pragma endregion

	while (TRUE)
	{
#pragma region INPUT_PROCESS
		command = readline("prompt : ");
		if (command != NULL)
			printf("Input : %s\n", command);
		else
			continue ;
		add_history(command);
#pragma endregion
		
#pragma region PARSING
		printf("\n\n==========PARSE SHELL==========\n");
		if (lexer_tokenize_command(command, &qtoken) <= FALSE)
		{
			;
		}
		free(command);
		if (parser_build_astree(&qtoken, &root) <= FALSE)
		{
			;
		}
#pragma endregion
		
#pragma region EXECUTION
		printf("\n\n==========EXECUTE SHELL==========\n");


#pragma endregion
	}
	return (0);
}