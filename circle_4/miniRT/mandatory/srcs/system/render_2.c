/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:47:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 14:36:05 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "minirt.h"

extern void	raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out);
extern void	raycast_plane(t_ray ray, t_object plane, t_rayinfo *out);
extern void	raycast_cylinder(t_ray ray, t_object cylinder, t_rayinfo *out);

static const t_rgb	g_skybox = {48, 205, 252};

t_rayinfo	trace_ray(t_ray	ray, t_scene *scene)
{
	t_object	obj;
	t_rayinfo	info;
	int			i;

	init_rayinfo(&info, ray.maxdist);
	i = 0;
	while (i < scene->vobject.size)
	{
		obj = *(t_object *)vector_get_idx(&(scene->vobject), i);
		if (obj.type == SPHERE)
			raycast_sphere(ray, obj, &info);
		else if (obj.type == PLANE)
			raycast_plane(ray, obj, &info);
		else if (obj.type == CYLINDER)
			raycast_cylinder(ray, obj, &info);
		++i;
	}
	return (info);
}

t_bool	is_shadowed(t_rayinfo *info, t_scene *scene)
{
	t_vec3		shadow_ray_pos;
	t_vec3		shadow_ray_dir;
	float		light_dist;
	t_ray		shadow_ray;
	t_rayinfo	shadow_info;

	shadow_ray_pos = vec3_plus_vec3(info->hitpos, \
								vec3_multiply_num(info->hitnorm, 0.01));
	shadow_ray_dir = vec3_minus_vec3(scene->light.position, info->hitpos);
	light_dist = sqrt(dot_vec3(shadow_ray_dir, shadow_ray_dir));
	shadow_ray_dir = normalize_vec3(shadow_ray_dir);
	shadow_ray = make_ray(shadow_ray_pos, shadow_ray_dir, light_dist);
	shadow_info = trace_ray(shadow_ray, scene);
	if (shadow_info.hitid == -1)
		return (FALSE);
	return (TRUE);
}

t_rgb	ambient_color(t_object *obj, t_scene *scene)
{
	t_rgb	color;

	color = vec3_multiply_vec3(obj->albedo, scene->ambient);
	return (color);
}

t_rgb	diffuse_color(t_object *obj, t_rayinfo *info, t_scene *scene)
{
	t_rgb	color;
	t_vec3	light_dir;
	double	diff;

	light_dir = normalize_vec3(vec3_minus_vec3(scene->light.position, \
										info->hitpos));
	diff = dot_vec3(info->hitnorm, light_dir);
	if (diff < 0)
		return (make_rgb(0, 0, 0));
	return (vec3_multiply_num(obj->albedo, diff));
}

t_rgb	per_pixel(t_ray ray, t_scene *scene)
{
	t_rgb		pixel_color;
	t_rayinfo	info;
	t_object	closest;

	info = trace_ray(ray, scene);
	if (info.hitid == -1)
		return (g_skybox);
	pixel_color = make_rgb(0, 0, 0);
	closest = *(t_object *)vector_get_idx(&(scene->vobject), info.hitid);
	pixel_color = vec3_plus_vec3(pixel_color, ambient_color(&closest, scene));
	if (is_shadowed(&info, scene) == TRUE)
		return (pixel_color);
	pixel_color = vec3_plus_vec3(pixel_color, \
						diffuse_color(&closest, &info, scene));
	clamp_vec3(&pixel_color, 0, 255);
	return (pixel_color);
}
