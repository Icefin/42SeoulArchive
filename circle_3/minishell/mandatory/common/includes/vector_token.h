/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_token.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:42:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/02 14:58:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TOKEN_H
# define VECTOR_TOKEN_H

# include "token.h"

typedef struct s_vector_token
{
	t_token		*data;
	int			size;
	int			capacity;
}	t_vector_token;

void	vector_token_constructor(t_vector_token *out, int size);
void	vector_token_destructor(t_vector_token *v);

void	vector_token_push_back(t_vector_token *v, t_token *t);
void	vector_token_pop_back(t_vector_token *v);

int		vector_token_is_empty(t_vector_token *v);

#endif