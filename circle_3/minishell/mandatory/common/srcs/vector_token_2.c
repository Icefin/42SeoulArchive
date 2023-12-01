/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_token_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:29:21 by geshin            #+#    #+#             */
/*   Updated: 2023/11/30 15:04:40 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "vector_token.h"

static void	realloc_vector_token(t_vector_token *out)
{
	t_vector_token	tmp;
	int				prev_size;
	int				i;

	prev_size = out->size;
	vector_token_constructor(&tmp, prev_size);
	i = -1;
	while (++i < prev_size)
		vector_token_push_back(&tmp, &(out->data[i]));
	vector_token_destructor(out);
	vector_token_constructor(out, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
		vector_token_push_back(out, &(tmp.data[i]));
	vector_token_destructor(&tmp);
}

void	vector_token_push_back(t_vector_token *v, t_token *t)
{
	if (v->size == v->capacity)
		realloc_vector_token(v);
	token_constructor(&(v->data[v->size]), t->type, &(t->data));
	++(v->size);
}

void	vector_token_pop_back(t_vector_token *v)
{
	token_destructor(&(v->data[v->size]));
	--(v->size);
}

int	vector_token_is_empty(t_vector_token *v)
{
	if (v->size == 0)
		return (TRUE);
	return (FALSE);
}
