/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_mesh.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:04:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 18:59:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_MESH_H
# define C_MESH_H

# include "gmathlib.h"
# include "vector.h"

typedef enum e_mesh_type
{
	CUBE,
	SPHERE,
	CYLINDER,
	PLANE
}	t_mesh_type;

typedef struct s_c_mesh
{
	t_mesh_type	type;

	t_vector	vertices;
	t_vector	indices;

}	t_c_mesh;

#endif