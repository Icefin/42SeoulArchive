/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:18:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/21 17:48:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"

void	vector_constructor(t_vector *out, int capacity, int dsize)
{
	out->dsize = dsize;
	out->capacity = capacity;
	out->data = malloc(dsize * capacity);
	out->size = 0;
}

void	vector_n_constructor(t_vector *out, int size, int dsize)
{
	out->dsize = dsize;
	out->capacity = size;
	out->data = malloc(dsize * size);
	out->size = size;
}

void	vector_destructor(t_vector *v)
{
	free(v->data);
}

void	vector_resize(t_vector *out, int size)
{
	t_vector	tmp;
	int			prev_size;
	int			i;

	prev_size = out->size;
	vector_constructor(&tmp, prev_size, out->dsize);
	i = -1;
	while (++i < prev_size)
		vector_push_back(&tmp, vector_get_idx(out, i));
	vector_destructor(out);
	vector_constructor(out, prev_size * 2, tmp.dsize);
	i = -1;
	while (++i < prev_size)
		vector_push_back(out, vector_get_idx(&tmp, i));
	vector_destructor(&tmp);
}