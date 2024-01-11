/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 18:49:57 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	make_sphere(t_vec3 pos, t_rgb albedo, float radius)
{
	t_object sphere;

	sphere.type = SPHERE;
	sphere.position = pos;
	sphere.albedo = albedo;
	sphere.radius = radius;
	return (sphere);
}

t_object	make_plane(t_vec3 pos, t_rgb albedo, t_vec3 normal)
{
	t_object plane;

	plane.type = PLANE;
	plane.position = pos;
	plane.albedo = albedo;
	plane.normal = normal;
	return (plane);
}

t_object	make_cylinder(t_vec3 pos, t_rgb albedo, float radius, t_vec3 axis, float length)
{
	t_object cylinder;

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
	t_object cone;

	cone.type = CONE;
	cone.position = pos;
	cone.albedo = albedo;
	cone.cos_a = cos_a;
	cone.axis = axis;
	cone.length = length;
	return (cone);
}