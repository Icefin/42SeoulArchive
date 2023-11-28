/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_string_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:04:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/11/29 02:04:26 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "vector_string.h"

void	vector_string_constructor(t_vector_string *out, int size)
{
	out->data = (t_string *)malloc(size * sizeof(t_string));
	out->size = 0;
	out->capacity = size;
}

void	vector_string_destructor(t_vector_string *v)
{
	int	i;

	if (v == NULL)
		return ;
	i = -1;
	while (++i < v->size)
		string_destructor(&(v->data[i]));
	free(v->data);
}
