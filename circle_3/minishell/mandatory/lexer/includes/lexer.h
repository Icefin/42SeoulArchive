/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 00:46:59 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "map_environment.h"
# include "vector_token.h"
# include "string.h"

/*
** Tokenize input command
*/
void	lexer_tokenize_command(char *cmd, t_map_env *menv, t_vector_token *out);

#endif