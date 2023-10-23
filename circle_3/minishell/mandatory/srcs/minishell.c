/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:38:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 18:30:57 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define	FALSE	0
#define	TRUE	1

static void	init_shell()
{
	return ;
}

int main(int argc, char **argv)
{
	char	*input;

	#pragma region SHELL_INIT
	printf("==========INIT SHELL==========\n");
	init_shell();
	#pragma endregion

	while (TRUE)
	{
		input = readline("prompt : ");
		if (input != NULL)
			printf("Input : %s\n", input);
		else
			continue ;
		add_history(input);
		#pragma region PARSING
		printf("\n\n==========PARSE SHELL==========\n");


		#pragma endregion

		free(input);

		#pragma region EXECUTION
		printf("\n\n==========EXECUTE SHELL==========\n");


		#pragma endregion
	}
	return (0);
}