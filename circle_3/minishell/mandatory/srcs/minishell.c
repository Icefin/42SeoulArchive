/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:38:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 15:36:37 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define	FALSE	0
#define	TRUE	1

static void	init_shell();

int main(int argc, char **argv)
{
	#pragma region SHELL_INIT
	printf("==========INIT SHELL==========\n");
	init_shell();
	#pragma endregion

	while (TRUE)
	{
		#pragma region PARSING
		printf("\n\n==========PARSE SHELL==========\n");


		#pragma endregion

		#pragma region LEXER
		printf("\n\n==========LEXER SHELL==========\n");


		#pragma endregion

		#pragma region EXECUTION
		printf("\n\n==========EXECUTE SHELL==========\n");


		#pragma endregion
	}
	return (0);
}