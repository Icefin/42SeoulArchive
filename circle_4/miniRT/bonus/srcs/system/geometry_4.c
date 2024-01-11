/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:56:45 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/05 15:40:02 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "rtmath.h"

extern float	intersect_plane(t_ray *ray, t_vec3 pos, t_vec3 norm, float *nd);

int	intersect_disk(t_ray *ray, t_vec3 position, float t, float radius)
{
	t_vec3	p;
	t_vec3	v;
	float	d2;

	p = vec3_plus_vec3(ray->origin, vec3_multiply_num(ray->direction, t));
	v = vec3_minus_vec3(p, position);
	d2 = dot_vec3(v, v);
	if (d2 > radius * radius)
		return (-1);
	return (0);
}

void	intersect_cylinder_cap(t_ray *ray, t_rayinfo *out, t_object cylinder)
{
	float	nd;
	float	t;

	t = intersect_plane(ray, cylinder.position, cylinder.axis, &nd);
	if (t < 1e-6 || t > out->raytime)
		return ;
	if (intersect_disk(ray, cylinder.position, t, cylinder.radius) != 0)
		return ;
	out->raytime = t;
	out->hitid = cylinder.id;
	out->hitpos = vec3_plus_vec3(ray->origin, \
		vec3_multiply_num(ray->direction, t));
	if (nd >= 1e-6)
		out->hitnorm = vec3_multiply_num(cylinder.axis, -1);
	else
		out->hitnorm = cylinder.axis;
}

void	raycast_cylinder_cap(t_ray *ray, t_rayinfo *out, t_object cylinder)
{
	t_object	tmp_cylinder;

	tmp_cylinder = cylinder;
	tmp_cylinder.axis = vec3_multiply_num(cylinder.axis, -1);
	intersect_cylinder_cap(ray, out, tmp_cylinder);
	tmp_cylinder = cylinder;
	tmp_cylinder.position = vec3_plus_vec3(cylinder.position, \
		vec3_multiply_num(cylinder.axis, cylinder.length));
	intersect_cylinder_cap(ray, out, tmp_cylinder);
}
