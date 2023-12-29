/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:47:47 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 15:50:17 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "minirt.h"

static const t_rgb skybox = {48, 205, 252};
static const t_rgb shadow = {0, 0, 0};

void		raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out);
void		raycast_plane(t_ray ray, t_object plane, t_rayinfo *out);
void		raycast_cylinder(t_ray ray, t_object cylinder, t_rayinfo *out);

t_rayinfo	trace_ray(t_ray	ray, t_scene *scene)
{
	t_rayinfo	info;

	init_rayinfo(&info, ray.maxdist);
	for (int i = 0; i < scene->vobject.size; ++i) {
		t_object obj = *(t_object *)vector_get_idx(&(scene->vobject), i);
		if (obj.type == SPHERE)
			raycast_sphere(ray, obj, &info);
		else if (obj.type == PLANE)
			raycast_plane(ray, obj, &info);
		else if (obj.type == CYLINDER)
			raycast_cylinder(ray, obj, &info);
	}
	return (info);
}

t_rgb	per_pixel(t_ray ray, t_scene *scene)
{
	t_rgb		pixel_color = make_rgb(0,0,0);
	t_rayinfo	info;

	info = trace_ray(ray, scene);
	if (info.hitid == -1)
		return skybox;
	
	t_vec3	shadow_ray_pos = vec3_plus_vec3(info.hitpos, vec3_multiply_num(info.hitnorm, 0.01));
	t_vec3	shadow_ray_dir = vec3_minus_vec3(scene->light.position, info.hitpos);
	float	light_dist = sqrt(dot_vec3(shadow_ray_dir, shadow_ray_dir));
	shadow_ray_dir = normalize_vec3(shadow_ray_dir);
	t_ray	shadow_ray = make_ray(shadow_ray_pos, shadow_ray_dir, light_dist);
	t_rayinfo	shadow_info = trace_ray(shadow_ray, scene);

	if (shadow_info.hitid != -1)
		return shadow;

	t_object closest = *(t_object *)vector_get_idx(&(scene->vobject), info.hitid);
	pixel_color = vec3_plus_vec3(pixel_color, vec3_multiply_vec3(closest.albedo, scene->ambient));
		
	t_vec3 lightDir = normalize_vec3(vec3_minus_vec3(scene->light.position, info.hitpos));
	double diff = dot_vec3(info.hitnorm, lightDir);
	if (diff < 0)
		diff = 0;
	pixel_color = vec3_plus_vec3(pixel_color, vec3_multiply_num(closest.albedo, diff));
	clamp_vec3(&pixel_color, 0, 255);
	return (pixel_color);
}

