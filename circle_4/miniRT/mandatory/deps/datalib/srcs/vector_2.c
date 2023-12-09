/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:52:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/09 21:32:08 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void	*vector_get_idx(const t_vector *v, int idx)
{
	if (idx >= v->size) {
		printf("Vector :: Index out of range\n");
		return (NULL);
	}
	return (v->data + v->dsize * idx);
}

void	vector_set_idx(const t_vector *v, int idx, const void *data)
{
	if (v->capacity <= idx) {
		printf("Vector :: Index out of range\n");
		return;
	}
	memcpy(v->data + v->dsize * idx, data, v->dsize);
}

void	vector_push_back(t_vector *v, const void *data)
{
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(*v->data) * v->capacity);
	}
	vector_set_idx(v, v->size, data);
	v->size++;
}

void	vector_pop_back(t_vector *v)
{
	if (v->size == 0) {
		printf("Vector :: Vector is empty");
		return;
	}
	v->size--;
}