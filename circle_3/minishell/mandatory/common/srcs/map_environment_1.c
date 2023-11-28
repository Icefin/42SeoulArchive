/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_environment_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:34 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/10 17:54:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commontype.h"
#include "map_environment.h"

void	map_environment_constructor(t_map_env *out, int size)
{
	vector_string_constructor(&out->key, size);
	vector_string_constructor(&out->value, size);
}

void	map_environment_destructor(t_map_env *m)
{
	if (m == NULL)
		return ;
	vector_string_destructor(&m->key);
	vector_string_destructor(&m->value);
}
