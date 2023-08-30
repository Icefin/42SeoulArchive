/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:54:21 by singeonho         #+#    #+#             */
/*   Updated: 2023/08/30 23:20:44 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

#include "vector.h"

typedef struct s_mesh
{
	t_vec4* vertices;
	int		numvertices;
}	t_mesh;

#endif