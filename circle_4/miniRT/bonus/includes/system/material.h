/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:32:42 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 16:22:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

#include "rtmath.h"

//http://devernay.free.fr/cours/opengl/materials.html

typedef enum s_surface_type
{
	METALLIC = 0,
	DIELECTRICS
}	t_surface_type;

typedef struct s_material
{
	t_rgb			ambient;
	t_rgb			diffuse;
	t_rgb			specular;
	float			shininess;

	t_surface_type	type;
}	t_material;

#endif