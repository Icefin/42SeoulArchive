/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:50 by geshin            #+#    #+#             */
/*   Updated: 2023/09/19 18:06:44 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_malloc(t_vector *v, int n)
{
	v->values = (int *)malloc(n * sizeof(int));
	v->size = 0;
	v->capacity = n;
}

void	vector_destroy(t_vector *v)
{
	free(v->values);
}

static void	vector_realloc(t_vector *v)
{
	t_vector	temp;
	int			prev_size;
	int			i;
	int			val;

	prev_size = v->size;
	vector_malloc(&temp, prev_size);
	i = -1;
	while (++i < prev_size)
	{
		val = vector_index_value(v, i);
		vector_push_back(&temp, val);
	}
	vector_destroy(v);
	vector_malloc(v, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
	{
		val = vector_index_value(&temp, i);
		vector_push_back(v, val);
	}
}

void	vector_push_back(t_vector *v, int val)
{
	if (v->size == v->capacity)
		vector_realloc(v);
	v->values[v->size] = val;
	v->size++;
}

void	vector_pop_back(t_vector *v)
{
	if (vector_is_empty(v) == TRUE)
	{
		printf("VPB : Vector is empty\n");
		exit(0);
	}
	v->size--;
}