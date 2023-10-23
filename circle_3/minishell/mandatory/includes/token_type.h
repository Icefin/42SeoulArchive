/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:43:58 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/23 17:39:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Special Symbol
<, >, <<, >>, &&, ||, |, ;
*/

#ifndef TOKEN_TYPE_H
# define TOKEN_TYPE_H

typedef enum e_token_type
{
	DOUBLE_AMPERSAND,
    DOUBLE_PIPE,
    PIPE,
    BRACKET,
    SIMPLE_CMD,
    REDIR_GREATER,
    REDIR_LESS,
    REDIR_APPEND,
    REDIR_HEREDOC,
    REDIR_ARG,
    WHITESPACE,
    DEFAULT,
    REDIRECT,
    REDIR_ARG_HEREDOC_QUOTED,
    AMPERSAND
}	t_token_type;

#endif