/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_token_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:27:58 by geshin            #+#    #+#             */
/*   Updated: 2023/11/29 02:03:34 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "commontype.h"
#include "vector_token.h"

void	vector_token_constructor(t_vector_token *out, int size)
{
	out->data = (t_token *)malloc(size * sizeof(t_token));
	out->size = 0;
	out->capacity = size;
}

void	vector_token_destructor(t_vector_token *v)
{
	int	i;

	if (v == NULL)
		return ;
	i = -1;
	while (++i < v->size)
		token_destructor(&(v->data[i]));
	free(v->data);
}
