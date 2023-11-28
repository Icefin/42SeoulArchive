/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_string_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:04:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:18:42 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "vector_string.h"

static void	realloc_vector_string(t_vector_string *out)
{
	t_vector_string	tmp;
	int				prev_size;
	int				i;

	prev_size = out->size;
	vector_string_constructor(&tmp, prev_size);
	i = -1;
	while (++i < prev_size)
		vector_string_push_back(&tmp, &(out->data[i]));
	vector_string_destructor(out);
	vector_string_constructor(out, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
		vector_string_push_back(out, &(tmp.data[i]));
	vector_string_destructor(&tmp);
}

void	vector_string_push_back(t_vector_string *v, t_string *s)
{
	char	*tmp;

	if (v->size == v->capacity)
		realloc_vector_string(v);
	tmp = get_string_c_str(s);
	string_constructor(&(v->data[v->size]), tmp);
	++(v->size);
	free(tmp);
}

void	vector_string_pop_back(t_vector_string *v)
{
	string_destructor(&(v->data[v->size - 1]));
	--(v->size);
}

void	vector_string_swap(t_vector_string *v, int i, int j)
{
	t_string	tmp;

	tmp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = tmp;
}

int	vector_string_is_empty(t_vector_string *v)
{
	if (v->size == 0)
		return (TRUE);
	return (FALSE);
}
