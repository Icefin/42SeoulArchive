/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:51:36 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 13:02:16 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "object.h"
#include "rtmath.h"

// void	raycast_cylinder_cap(t_ray ray, t_rayinfo *out, t_object *cylinder, t_vec3 position, t_vec3 normal)
// {
// 	float nd = dot_vec3(ray.direction, normal);
// 	float pn = dot_vec3(ray.origin, normal);
// 	float d = sqrt(dot_vec3(position, position));

// 	if (nd >= 0.0f)
// 		return;

// 	float t = (d - pn) / nd;
// 	if (t < 1e-6 || t > out->raytime)
// 		return ;
// 	t_vec3	p = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, t));
// 	t_vec3	v = vec3_minus_vec3(p, cylinder->position);
// 	float	d2 = dot_vec3(v, v);
// 	if (d2 > cylinder->radius * cylinder->radius)
// 		return ;
// 	out->raytime = t;
// 	out->hitid = cylinder->id;
// 	out->hitnorm = normal;
// 	out->hitpos = p;
// }

void	raycast_cylinder_cap(t_ray ray, t_rayinfo *out, t_object *cylinder, t_vec3 position, t_vec3 normal)
{
	t_vec3	oc = vec3_minus_vec3(ray.origin, position);
	float	dn = dot_vec3(ray.direction, normal);
	float	ocn = dot_vec3(vec3_multiply_num(oc, -1), normal);

	if (dn >= 0)
		return ;

	float	t = ocn / dn;
	if (t < 1e-6 || t > out->raytime)
		return ;
	t_vec3	p = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, t));
	t_vec3	v = vec3_minus_vec3(p, position);
	float	d2 = dot_vec3(v, v);
	if (d2 > cylinder->radius * cylinder->radius)
		return ;
	out->raytime = t;
	out->hitid = cylinder->id;
	out->hitnorm = normal;
	out->hitpos = p;
}

//ray-cylinder relation
void	raycast_cylinder(t_ray ray, t_object cylinder, t_rayinfo *out)
{
	t_vec3	oc = vec3_minus_vec3(ray.origin, cylinder.position);
	t_vec3	cl;
	float	a = dot_vec3(ray.direction, ray.direction) - pow(dot_vec3(ray.direction, cylinder.axis), 2.0);
	float	half_b = (dot_vec3(ray.direction, oc) - (dot_vec3(ray.direction, cylinder.axis) * dot_vec3(oc, cylinder.axis)));
	float	c = dot_vec3(oc, oc) - pow(dot_vec3(oc, cylinder.axis), 2.0) - pow(cylinder.radius, 2.0);
	float	disc = (half_b * half_b) - (a * c);
	float	t;
	float	m;

	raycast_cylinder_cap(ray, out, &cylinder, vec3_plus_vec3(cylinder.position, vec3_multiply_num(cylinder.axis, cylinder.length)), cylinder.axis);
	raycast_cylinder_cap(ray, out, &cylinder, cylinder.position, vec3_multiply_num(cylinder.axis, -1));
	if (disc < 0)
		return ;
	t = (-half_b - sqrt(disc)) / a;
	if (t < 1e-6 || t > out->raytime)
	{
		t = (-half_b + sqrt(disc)) / a;
		if (t < 1e-6 || t > out->raytime)
			return ;
	}
	m = dot_vec3(ray.direction, vec3_multiply_num(cylinder.axis, t)) + dot_vec3(oc, cylinder.axis);
	// m = dot_vec3(vec3_plus_vec3(vec3_multiply_num(ray.direction, t), oc), cylinder.axis);
	if (m < 0 || m > cylinder.length)
		return ;
	out->hitid = cylinder.id;
	out->raytime = t;
	out->hitpos = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, t));
	out->hitnorm = normalize_vec3(vec3_minus_vec3(vec3_minus_vec3(out->hitpos, cylinder.position), vec3_multiply_num(cylinder.axis, m)));
}
