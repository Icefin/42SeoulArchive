/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:51:55 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/09 21:31:28 by singeonho        ###   ########.fr       */
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

void	vector_destructor(t_vector *v)
{
	free(v->data);
}