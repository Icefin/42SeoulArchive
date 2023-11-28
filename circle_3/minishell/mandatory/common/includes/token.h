/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:02:34 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "string.h"

typedef enum e_token_type
{
	DEFAULT = -1,
	END = 0,
	ERROR = 256,
	WORD = 258,
	SLESS = 259,
	SGREAT = 260,
	DLESS = 261,
	DGREAT = 262,
	PIPE = 263,
	CMD_NAME = 10,
	CMD_WORD = 11,
	FILE_NAME = 12,
	HERE_END = 13,
	IO_FILE = 14,
	IO_HERE = 15,
	IO_REDIRECT = 16,
	CMD_PREFIX = 17,
	CMD_SUFFIX = 18,
	SIMPLE_COMMAND = 19,
	PIPE_SEQUENCE = 20
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	t_string		data;
}	t_token;

void	token_constructor(t_token *out, t_token_type type, t_string *data);
void	token_destructor(t_token *token);

#endif