/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:09:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/08 13:59:31 by jihwjeon         ###   ########.fr       */
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

t_object	make_cylinder(t_vec3 pos, t_rgb albedo, t_vec3 axis)
{
	t_object	cylinder;

	cylinder.type = CYLINDER;
	cylinder.position = pos;
	cylinder.albedo = albedo;
	cylinder.axis = axis;
	return (cylinder);
}
