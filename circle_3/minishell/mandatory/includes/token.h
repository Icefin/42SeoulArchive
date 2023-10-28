/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/28 17:29:49 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
    //Terminal Symbols
	WORD,
    SLESS,
    SGREAT,
    DLESS,
    DGREAT,
    PIPE,

    //Non-terminal Symbols
    CMD_NAME,
	CMD_WORD,
	FILENAME,
	HERE_END,

	IO_FILE,
	IO_HERE,
	IO_REDIRECT,

	CMD_PREFIX,
	CMD_SUFFIX,
	SIMPLE_COMMAND,
	PIPE_SEQUENCE
}	t_token_type;

typedef struct s_token
{
    t_token_type    type;
    char            *data;
}   t_token;

t_token *token_constructor(t_token_type type, char *data);
void    token_destructor();

#endif