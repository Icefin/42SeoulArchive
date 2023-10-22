/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:46 by geshin            #+#    #+#             */
/*   Updated: 2023/10/22 16:39:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vector_get_index_value(t_vector *v, int idx)
{
	if (idx >= v->size)
	{
		destroy_vector(v);
		exit(1);
	}
	return (v->values[idx]);
}

int	vector_get_back(t_vector *v)
{
	if (v->size == 0)
	{
		destroy_vector(v);
		exit(1);
	}
	return (v->values[v->size - 1]);
}

int	vector_is_empty(t_vector *v)
{
	if (v->size == 0)
		return (TRUE);
	return (FALSE);
}
