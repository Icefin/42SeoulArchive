/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:01:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/20 12:33:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "rtmath.h"
# include "commontype.h"

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
	t_rgb			albedo;

	//Plane
	t_vec3			normal;

	//Sphere && Cylinder
	float			radius;

	//Cylinder
	t_vec3			axis;
	float			length;
}	t_object;

t_object	make_sphere(t_vec3 pos, t_rgb albedo, float radius);
t_object	make_plane(t_vec3 pos, t_rgb albedo, t_vec3 normal);
t_object	make_cylinder(t_vec3 pos, t_rgb albedo, float radius, t_vec3 axis, float length);


#endif