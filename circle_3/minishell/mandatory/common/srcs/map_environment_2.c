/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_environment_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:38:04 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:03:05 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map_environment.h"
#include "commontype.h"
#include "string.h"

void	map_environment_insert(t_map_env *m, t_string *key, t_string *value)
{
	int		idx;
	char	*tmp;

	idx = map_environment_find_index(m, key);
	if (idx < 0)
	{
		vector_string_push_back(&m->key, key);
		vector_string_push_back(&m->value, value);
	}
	else
	{
		tmp = get_string_c_str(value);
		string_destructor(&(m->value.data[idx]));
		string_constructor(&(m->value.data[idx]), tmp);
		free(tmp);
	}
}

int	map_environment_find_index(t_map_env *m, t_string *key)
{
	int	idx;

	idx = -1;
	while (++idx < m->key.size)
	{
		if (string_compare(&m->key.data[idx], key) == TRUE)
			return (idx);
	}
	return (-1);
}

void	map_environment_erase(t_map_env *m, t_string *key)
{
	int	idx;

	idx = map_environment_find_index(m, key);
	if (idx < 0)
		return ;
	if (idx != m->key.size - 1)
	{
		vector_string_swap(&m->key, idx, m->key.size - 1);
		vector_string_swap(&m->value, idx, m->value.size - 1);
	}
	vector_string_pop_back(&m->key);
	vector_string_pop_back(&m->value);
}
