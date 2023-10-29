/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/30 03:48:47 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
    //Terminal Symbols
	WORD = 0,
    SLESS = 1,
    SGREAT = 2,
    DLESS = 3,
    DGREAT = 4,
    PIPE = 5,

    //Non-terminal Symbols
    CMD_NAME = 100,
	CMD_WORD = 101,
	FILENAME = 102,
	HERE_END = 103,

	IO_FILE = 104,
	IO_HERE = 105,
	IO_REDIRECT = 106,

	CMD_PREFIX = 107,
	CMD_SUFFIX = 108,
	SIMPLE_COMMAND = 109,
	PIPE_SEQUENCE = 110
}	t_token_type;

typedef struct s_token
{
    t_token_type    type;
    char            *data;
}   t_token;

t_token *token_constructor(t_token_type type, char *data);
void    token_destructor();

#endif