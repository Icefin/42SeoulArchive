/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 17:23:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "astree.h"
# include "queue_token.h"

typedef enum e_action
{
	SHIFT,
	REDUCE,
	ACCEPT,
	ERROR
}	t_action;

/*
** Build ASTree from vector<token>
** Can Build ASTree : return TRUE(1)
** Cannot Build ASTree : return FALSE(0)
*/
int	parser_build_astree(t_queue_token *q, t_ast_node *out);

#endif

/*
Automaton...

```
Syntax Rules

cmd_name		: WORD
			;
cmd_word		: WORD
			;
filename		: WORD
			;
here_end		: WORD
			;

io_file			: SLESS		filename
			| SGREAT	filename
			| DGREAT	filename
			;
io_here			: DLESS		here_end
			;
io_redirect		: io_file
			| io_here
			;

cmd_prefix		: io_redirect
			| cmd_prefix	io_redirect
			;
cmd_suffix		: io_redirect
			| cmd_suffix	io_redirect
			| WORD
			| cmd_suffix	WORD
			;
simple_command		: cmd_prefix	cmd_word	cmd_suffix
			| cmd_prefix	cmd_word
			| cmd_prefix
			| cmd_name	cmd_suffix
			| cmd_name
			;

pipe_sequence		: simple_command
			| pipe_sequence PIPE simple_command
			;
```
*/