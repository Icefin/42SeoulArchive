/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/11 17:05:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	make_sphere(t_vec3 pos, t_rgb albedo, float radius)
{
	t_object	sphere;

	sphere.type = SPHERE;
	sphere.position = pos;
	sphere.albedo = albedo;
	sphere.radius = radius;
	return (sphere);
}

t_object	make_plane(t_vec3 pos, t_rgb albedo, t_vec3 normal)
{
	t_object	plane;

	plane.type = PLANE;
	plane.position = pos;
	plane.albedo = albedo;
	plane.normal = normal;
	return (plane);
}

t_object	make_cylinder(t_vec3 pos, t_rgb albedo, float radius, t_vec3 axis, float length)
{
	t_object 	cylinder;

	cylinder.type = CYLINDER;
	cylinder.position = pos;
	cylinder.albedo = albedo;
	cylinder.radius = radius;
	cylinder.axis = axis;
	cylinder.length = length;
	return (cylinder);
}

t_object	make_cone(t_vec3 pos, t_rgb albedo, float cos_a, t_vec3 axis, float length)
{
	t_object	cone;

	cone.type = CONE;
	cone.position = pos;
	cone.albedo = albedo;
	cone.cos_a = cos_a;
	cone.axis = axis;
	cone.length = length;
	return (cone);
}

t_object	make_triangle(t_vec3 t1, t_vec3 t2, t_vec3 t3, t_rgb albedo)
{
	t_object	triangle;

	triangle.type = TRIANGLE;
	triangle.albedo = albedo;
	triangle.t1 = t1;
	triangle.t2 = t2;
	triangle.t3 = t3;
	triangle.normal = normalize_vec3(cross_vec3(vec3_minus_vec3(t3, t2), vec3_minus_vec3(t1, t2)));
	return (triangle);
}