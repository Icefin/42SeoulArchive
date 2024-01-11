/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:50:05 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 15:55:52 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "object.h"
#include "rtmath.h"
#include <math.h>

float	intersect_sphere(t_ray *ray, t_object *sphere, t_rayinfo *out, float d)
{
	t_vec3	oc;
	float	a;
	float	half_b;
	float	c;
	float	t;

	oc = vec3_minus_vec3(ray->origin, sphere->position);
	a = dot_vec3(ray->direction, ray->direction);
	half_b = dot_vec3(oc, ray->direction);
	c = dot_vec3(oc, oc) - (sphere->radius * sphere->radius);
	d = (half_b * half_b) - (a * c);
	if (d < 0)
		return (-1);
	t = (-half_b - sqrt(d)) / a;
	if (t < 1e-6 || t > out->raytime)
	{
		t = (-half_b + sqrt(d)) / a;
		if (t < 1e-6 || t > out->raytime)
			return (-1);
	}
	return (t);
}

void	raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out)
{
	float	discriminant;
	float	t;

	t = intersect_sphere(&ray, &sphere, out, discriminant);
	if (t < 1e-6 || t > out->raytime)
		return ;
	out->hitid = sphere.id;
	out->raytime = t;
	out->hitpos = vec3_plus_vec3(ray.origin, \
					vec3_multiply_num(ray.direction, t));
	out->hitnorm = vec3_multiply_num(\
					vec3_minus_vec3(out->hitpos, sphere.position), \
					1 / sphere.radius);
	if (dot_vec3(ray.direction, out->hitnorm) > 0)
		out->hitnorm = vec3_multiply_num(out->hitnorm, -1);
}
