/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:50 by geshin            #+#    #+#             */
/*   Updated: 2023/10/11 17:02:04 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	malloc_vector(t_vector *v, int n)
{
	v->values = (int *)malloc(n * sizeof(int));
	v->size = 0;
	v->capacity = n;
}

void	destroy_vector(t_vector *v)
{
	if (v->values != NULL)
		free(v->values);
}

static void	realloc_vector(t_vector *v)
{
	t_vector	temp;
	int			prev_size;
	int			i;
	int			val;

	prev_size = v->size;
	malloc_vector(&temp, prev_size);
	i = -1;
	while (++i < prev_size)
	{
		val = vector_index_value(v, i);
		vector_push_back(&temp, val);
	}
	destroy_vector(v);
	malloc_vector(v, 2 * prev_size);
	i = -1;
	while (++i < prev_size)
	{
		val = vector_index_value(&temp, i);
		v->values[i] = val;
	}
}

void	vector_push_back(t_vector *v, int val)
{
	if (v->size == v->capacity)
		realloc_vector(v);
	v->values[v->size] = val;
	v->size++;
}

void	vector_pop_back(t_vector *v)
{
	if (vector_is_empty(v) == TRUE)
	{
		printf("Error::VPB : Vector is empty\n");
		destroy_vector(v);
		exit(0);
	}
	v->size--;
}
