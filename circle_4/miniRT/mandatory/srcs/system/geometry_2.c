/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:51:17 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 15:34:57 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "object.h"
#include "rtmath.h"

float	intersect_plane(t_ray *ray, t_vec3 position, t_vec3	normal, float *nd)
{
	t_vec3	oc;
	float	noc;
	float	t;

	(*nd) = dot_vec3(ray->direction, normal);
	if ((*nd) >= 0 && (*nd) <= 1e-6)
		return (-1);
	oc = vec3_minus_vec3(position, ray->origin);
	noc = dot_vec3(oc, normal);
	t = noc / (*nd);
	return (t);
}

void	raycast_plane(t_ray ray, t_object plane, t_rayinfo *out)
{
	float	nd;
	float	t;

	t = intersect_plane(&ray, plane.position, plane.normal, &nd);
	if (t < 1e-6 || t > out->raytime)
		return ;
	out->raytime = t;
	out->hitid = plane.id;
	out->hitpos = vec3_plus_vec3(ray.origin, \
					vec3_multiply_num(ray.direction, t));
	if (nd >= 1e-6)
		out->hitnorm = vec3_multiply_num(plane.normal, -1);
	else
		out->hitnorm = plane.normal;
}
