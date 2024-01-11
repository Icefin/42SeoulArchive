/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:51:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/01 22:39:27 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "object.h"
#include "rtmath.h"

extern void	raycast_cylinder_cap(t_ray *ray, t_rayinfo *out, t_object cylinder);

float	calc_cy_discriminant(t_ray *ray, t_object *cy, float *a, float *half_b)
{
	t_vec3	oc;
	float	c;
	float	disc;

	oc = vec3_minus_vec3(ray->origin, cy->position);
	*a = dot_vec3(ray->direction, ray->direction) - \
		pow(dot_vec3(ray->direction, cy->axis), 2.0);
	*half_b = (dot_vec3(ray->direction, oc) - \
			(dot_vec3(ray->direction, cy->axis) * dot_vec3(oc, cy->axis)));
	c = dot_vec3(oc, oc) - pow(dot_vec3(oc, cy->axis), 2.0) - \
		pow(cy->radius, 2.0);
	disc = (*half_b * *half_b) - (*a * c);
	return (disc);
}

float	intersect_cylinder(t_ray *ray, t_object *cy, t_rayinfo *out, float t)
{
	float	a;
	float	half_b;
	float	disc;

	disc = calc_cy_discriminant(ray, cy, &a, &half_b);
	if (disc < 0)
		return (-1);
	t = (-half_b - sqrt(disc)) / a;
	if (t < 1e-6 || t > out->raytime)
	{
		t = (-half_b + sqrt(disc)) / a;
		if (t < 1e-6 || t > out->raytime)
			return (-1);
	}
	return (t);
}

void	raycast_cylinder(t_ray ray, t_object cylinder, t_rayinfo *out)
{
	t_vec3	oc;
	float	t;
	float	m;

	raycast_cylinder_cap(&ray, out, cylinder);
	t = intersect_cylinder(&ray, &cylinder, out, t);
	if (t < 1e-6 || t > out->raytime)
		return ;
	oc = vec3_minus_vec3(ray.origin, cylinder.position);
	m = dot_vec3(ray.direction, \
		vec3_multiply_num(cylinder.axis, t)) + dot_vec3(oc, cylinder.axis);
	if (m < 0 || m > cylinder.length)
		return ;
	out->hitid = cylinder.id;
	out->raytime = t;
	out->hitpos = vec3_plus_vec3(ray.origin, \
		vec3_multiply_num(ray.direction, t));
	out->hitnorm = normalize_vec3(\
		vec3_minus_vec3(vec3_minus_vec3(out->hitpos, cylinder.position), \
		vec3_multiply_num(cylinder.axis, m)));
	if (dot_vec3(ray.direction, out->hitnorm) > 0)
		out->hitnorm = vec3_multiply_num(out->hitnorm, -1);
}
