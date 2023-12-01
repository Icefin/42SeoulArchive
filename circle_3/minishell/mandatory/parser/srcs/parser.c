/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:19:55 by geshin            #+#    #+#             */
/*   Updated: 2023/12/01 16:56:53 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "commontype.h"
#include "automaton.h"
#include "parser.h"

//#define PARSER_DEBUG

#ifdef PARSER_DEBUG
	char brench[3] = {'R', '\\', '/'};

	void post_order(t_node *root, int space, int dir)
	{
		if (root == NULL)
			return ;

		space += 6;
		post_order(root->right, space, 2);
		printf("\n");
		for (int i = 6; i < space; ++i)
			printf(" ");
		char *str = get_string_c_str(&(root->token.data));
		printf("%c%d(%s)\n", brench[dir], root->token.type, str);
		free(str);
		post_order(root->left, space, 1);
	}

	void debug_print_astree(t_node *root) {
		printf("ASTREE : \n");
		post_order(root, 0, 0);
	}
#endif

void	parser_build_astree(t_vector_token *v, t_node **out, t_map_env *menv)
{
	t_automaton	atm;

	automaton_constructor(&atm);
	automaton_process(&atm, v);
	automaton_get_result(&atm, out);
	if (*out == NULL)
	{
		printf("Parse Error : Invalid Syntax\n");
		menv->exit_status = 258;
	}
	automaton_destructor(&atm);
}
