/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:46 by geshin            #+#    #+#             */
/*   Updated: 2023/10/12 15:07:49 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vector_get_index_value(t_vector *v, int idx)
{
	if (idx >= v->size)
	{
		printf("Error::VIV : Vector script out of range\n");
		destroy_vector(v);
		exit(0);
	}
	return (v->values[idx]);
}

int	vector_get_back(t_vector *v)
{
	if (v->size == 0)
	{
		printf("Error::VGB : Vector is empty\n");
		destroy_vector(v);
		exit(0);
	}
	return (v->values[v->size - 1]);
}

int	vector_is_empty(t_vector *v)
{
	if (v->size == 0)
		return (TRUE);
	return (FALSE);
}
