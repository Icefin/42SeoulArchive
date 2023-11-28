/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:52:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 07:05:20 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "astree.h"
# include "vector_token.h"

/*
** Build ASTree from vector<token>
*/
void	parser_build_astree(t_vector_token *v, t_node **out);

#endif