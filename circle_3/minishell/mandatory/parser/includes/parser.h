/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/30 14:14:50 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "astree.h"
# include "vector_token.h"
# include "map_environment.h"

/*
** Build ASTree from vector<token>
*/
void	parser_build_astree(t_vector_token *v, t_node **out, t_map_env *menv);

#endif