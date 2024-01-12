/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:05:51 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/11 17:19:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "ray.h"
#include "rtmath.h"

extern float intersect_plane(t_ray *ray, t_vec3 position, t_vec3 normal, float *nd);
extern void	raycast_plane(t_ray ray, t_object plane, t_rayinfo *out);

void raycast_triangle(t_ray ray, t_object triangle, t_rayinfo *out)
{
	float	nd;
	float	t;

	t = intersect_plane(&ray, triangle.t1, triangle.normal, &nd);
	if (t < 1e-6 || t > out->raytime)
		return ;
	t_vec3	p = vec3_plus_vec3(ray.origin, vec3_multiply_num(ray.direction, t));

	t_vec3	pa = vec3_minus_vec3(p, triangle.t1);
	t_vec3	pb = vec3_minus_vec3(p, triangle.t2);
	t_vec3 	pc = vec3_minus_vec3(p, triangle.t3);

	t_vec3 u = cross_vec3(pa, pb);
	t_vec3 v = cross_vec3(pb, pc);
	t_vec3 w = cross_vec3(pc, pa);

	if (dot_vec3(u, v) < 0.0f)
		return ;
	if (dot_vec3(u, w) < 0.0f)
		return ;

	out->raytime = t;
	out->hitid = triangle.id;
	if (nd >= 1e-6)
		out->hitnorm = vec3_multiply_num(triangle.normal, -1);
	else
		out->hitnorm = triangle.normal;
	out->hitpos = p;
}