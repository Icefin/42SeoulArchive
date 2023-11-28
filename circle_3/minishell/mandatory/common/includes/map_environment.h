/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_environment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:32:23 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/11/29 02:02:17 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ENVIRONMENT_H
# define MAP_ENVIRONMENT_H

# include "vector_string.h"

typedef struct s_map_env
{
	t_vector_string	key;
	t_vector_string	value;
}	t_map_env;

void	map_environment_constructor(t_map_env *out, int size);
void	map_environment_destructor(t_map_env *m);

void	map_environment_insert(t_map_env *m, t_string *key, t_string *value);
int		map_environment_find_index(t_map_env *m, t_string *key);
void	map_environment_erase(t_map_env *m, t_string *key);

#endif