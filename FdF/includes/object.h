/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:27:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/08/30 23:30:49 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

#include "vector.h"

typedef struct s_object
{
	t_vec4* vertices;
	int		numvertices;
}	t_object;

void	load_object(t_object* object, char* path);

#endif