/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:40:59 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/08 15:49:08 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "ray.h"
#include "rtmath.h"

extern float	intersect_plane(t_ray *ray, t_vec3 pos, t_vec3 norm, float *nd);
extern int		intersect_disk(t_ray *ray, t_vec3 position, float t, float r);

float	calc_cone_discriminant(t_ray *ray, t_object *cn, float *a, float *b)
{
	t_vec3	oc;
	float	c;
	float	disc;

	oc = vec3_minus_vec3(ray->origin, cn->position);
	*a = pow(dot_vec3(ray->direction, cn->axis), 2.0) - pow(cn->cos_a, 2.0);
	*b = 2.0 * ((dot_vec3(ray->direction, cn->axis) * dot_vec3(oc, cn->axis)) - \
		(dot_vec3(ray->direction, oc) * pow(cn->cos_a, 2.0)));
	c = pow(dot_vec3(oc, cn->axis), 2.0) - \
		(dot_vec3(oc, oc) * pow(cn->cos_a, 2.0));
	disc = (*b * *b) - (4 * *a * c);
	return (disc);
}

float	intersect_cone(t_ray *ray, t_object *cone, t_rayinfo *out)
{
	float	a;
	float	b;
	float	disc;
	float	t;

	disc = calc_cone_discriminant(ray, cone, &a, &b);
	if (disc < 0)
		return (-1);
	t = (-b + sqrt(disc)) / (2 * a);
	if (t < 1e-6 || t > out->raytime)
	{
		t = (-b - sqrt(disc)) / (2 * a);
		if (t < 1e-6 || t > out->raytime)
			return (-1);
	}
	return (t);
}

void	raycast_cone_cap(t_ray *ray, t_rayinfo *out, t_object cone)
{
	float	nd;
	float	t;

	cone.position = vec3_plus_vec3(cone.position, \
						vec3_multiply_num(cone.axis, cone.length));
	t = intersect_plane(ray, cone.position, cone.axis, &nd);
	if (t < 1e-6 || t > out->raytime)
		return ;
	if (intersect_disk(ray, cone.position, t, cone.radius) != 0)
		return ;
	out->raytime = t;
	out->hitid = cone.id;
	out->hitpos = vec3_plus_vec3(ray->origin, \
		vec3_multiply_num(ray->direction, t));
	if (nd >= 1e-6)
		out->hitnorm = vec3_multiply_num(cone.axis, -1);
	else
		out->hitnorm = cone.axis;
}

void	raycast_cone(t_ray ray, t_object cone, t_rayinfo *out)
{
	t_vec3	cp;
	t_vec3	oc;
	float	t;
	float	m;
	float	k;

	raycast_cone_cap(&ray, out, cone);
	t = intersect_cone(&ray, &cone, out);
	if (t < 1e-6 || t > out->raytime)
		return ;
	oc = vec3_minus_vec3(ray.origin, cone.position);
	m = dot_vec3(ray.direction, vec3_multiply_num(cone.axis, t)) + \
		dot_vec3(oc, cone.axis);
	if (m < 0 || m > cone.length)
		return ;
	out->hitid = cone.id;
	out->raytime = t;
	out->hitpos = vec3_plus_vec3(ray.origin, \
		vec3_multiply_num(ray.direction, t));
	k = sqrt((1 - pow(cone.cos_a, 2.0))) / cone.cos_a;
	out->hitnorm = normalize_vec3(\
		vec3_minus_vec3(vec3_minus_vec3(out->hitpos, cone.position), \
		vec3_multiply_num(cone.axis, m * (1 + pow(k, 2.0)))));
	if (dot_vec3(ray.direction, out->hitnorm) >= 0)
		out->hitnorm = vec3_multiply_num(out->hitnorm, -1);
}
