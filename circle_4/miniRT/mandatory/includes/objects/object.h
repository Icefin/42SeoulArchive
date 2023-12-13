/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:01:37 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 19:12:08 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "commontype.h"
#include "gmathlib.h"

typedef enum e_object_type
{
	SPHERE = 0,
	PLANE,
	CYLINDER,
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
	t_uint32		id;

	t_vec3			position;
	t_rgb			rgb;

	//Plane
	t_vec3			normal;

	//Sphere
	t_uint32		radius;

	//Cylinder
	t_vec3			axis;
	t_uint32		radius;
	t_uint32		length;
}	t_object;



#endif