/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:20:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 19:10:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "gmathlib.h"
#include "geometry.h"

void	raycast_sphere(const t_ray *ray, const t_object *sphere, t_rayinfo *out)
{
	out->raytime = -1.0;
	t_vec3 toSphere = vec3_minus_vec3(&(sphere->position), &(ray->origin));

	float squareRadius = sphere->radius * sphere->radius;
	float squareDistance = dot_vec3(&toSphere, &toSphere);
	float tangentLength = dot_vec3(&toSphere, &(ray->direction));
		
	if (squareRadius + tangentLength * tangentLength < squareDistance)
		return;

	float squarePerpLength = squareDistance - (tangentLength * tangentLength);
	float penetratedLength = sqrt(squareRadius - squarePerpLength);

	// Outer || Inner Check
	float t = (squareDistance > squareRadius) ?  tangentLength - penetratedLength : tangentLength + penetratedLength;

	out->hit_position = ray->origin;
	t_vec3 offset = vec3_multiply_num(&(ray->direction), t);
	out->hit_position = vec3_plus_vec3(&(out->hit_position), &offset);
	out->hit_normal = vec3_minus_vec3(&(out->hit_position), &(sphere->position));
	out->hit_normal = normalize_vec3(&(out->hit_normal));
	out->raytime = t;
}

void	raycast_plane(const t_ray *ray, const t_object *plane, t_rayinfo *out)
{
	out->raytime = -1.0;
	float nd = dot_vec3(&(ray->direction), &(plane->normal));
	float pn = dot_vec3(&(ray->origin), &(plane->normal));

	if (nd >= 0.0f)
		return;

	float t = (plane->distance - pn) / nd;

	if (t >= 0.0f)
	{
		out->hit_position = ray->origin + t * ray->direction;
		out->hit_normal = plane->normal;
		out->raytime = t;
	}
}

void	raycast_cylinder(const t_ray *ray, const t_object *cylinder, t_rayinfo *out)
{

}
