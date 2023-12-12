/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:42:56 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/12 16:20:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "vector.h"

typedef enum e_type
{
	SPHERE,
	CUBE,
	PLANE,
	CYLINDER,
	TRIANGLE
}	t_type;

typedef struct s_mesh
{
	t_type		type;
	t_vector	vertices;
	t_vector	indices;

}	t_mesh;

#endif