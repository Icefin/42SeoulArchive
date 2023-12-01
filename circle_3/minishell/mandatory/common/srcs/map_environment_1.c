/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_environment_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:34 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/30 13:50:47 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_environment.h"

void	map_environment_constructor(t_map_env *out, int size)
{
	vector_string_constructor(&out->key, size);
	vector_string_constructor(&out->value, size);
	out->exit_status = 0;
}

void	map_environment_destructor(t_map_env *m)
{
	if (m == 0)
		return ;
	vector_string_destructor(&m->key);
	vector_string_destructor(&m->value);
}
