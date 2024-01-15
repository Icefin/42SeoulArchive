/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:47:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 21:57:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "minirt.h"

#define RECURSIVE_MAX 3

extern void	raycast_sphere(t_ray ray, t_object sphere, t_rayinfo *out);
extern void	raycast_plane(t_ray ray, t_object plane, t_rayinfo *out);
extern void	raycast_cylinder(t_ray ray, t_object cylinder, t_rayinfo *out);
extern void	raycast_cone(t_ray ray, t_object cone, t_rayinfo *out);
extern void raycast_triangle(t_ray ray, t_object triangle, t_rayinfo *out);

static const t_rgb skybox = {0, 0, 0};

t_rayinfo	raycast(t_ray	ray, t_scene *scene)
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
		else if (obj.type == CONE)
			raycast_cone(ray, obj, &info);
		else if (obj.type == TRIANGLE)
			raycast_triangle(ray, obj, &info);
	}
	return (info);
}

t_bool is_shadowed(t_rayinfo *info, t_light  *light, t_scene *scene)
{
	t_vec3		shadow_ray_pos;
	t_vec3		shadow_ray_dir;
	float		light_dist;
	t_ray		shadow_ray;
	t_rayinfo	shadow_info;

	shadow_ray_pos = vec3_plus_vec3(info->hitpos, vec3_multiply_num(info->hitnorm, 0.01));
	shadow_ray_dir = vec3_minus_vec3(light->position, info->hitpos);
	light_dist = sqrt(dot_vec3(shadow_ray_dir, shadow_ray_dir));
	shadow_ray_dir = normalize_vec3(shadow_ray_dir);
	shadow_ray = make_ray(shadow_ray_pos, shadow_ray_dir, light_dist);
	shadow_info = raycast(shadow_ray, scene);
	if (shadow_info.hitid == -1)
		return (FALSE);
	return (TRUE);
}

t_rgb	ambient_color(t_rgb albedo, t_rgb ambient)	
{
	t_rgb	color;

	color = vec3_multiply_vec3(albedo, ambient);
	return (color);
}

t_rgb	diffuse_color(t_rayinfo *info, t_rgb albedo, t_vec3 normal, t_light *light)
{
	t_rgb	color;
	t_vec3	lightDir;
	float	diff;

	lightDir = normalize_vec3(vec3_minus_vec3(light->position, info->hitpos));
	diff = fmax(dot_vec3(normal, lightDir), 0);
	return (vec3_multiply_num(vec3_multiply_vec3(albedo, light->albedo), diff));
}

t_rgb	specular_color(t_ray *ray, t_rayinfo *info, t_rgb albedo, t_vec3 normal, t_light *light)
{
	t_rgb	color;
	t_vec3	incident;
	t_vec3	view;
	t_vec3	reflect;
	float	spec;

	incident = normalize_vec3(vec3_minus_vec3(info->hitpos, light->position));
	reflect = normalize_vec3(reflect_vec3(incident, normal));
	view = vec3_multiply_num(ray->direction, -1);
	spec =pow(fmax(dot_vec3(reflect, view), 0), 10);
	return (vec3_multiply_num(vec3_multiply_vec3(light->albedo, albedo), spec));
}

t_rgb	trace_ray(t_ray ray, t_scene *scene, int depth)
{
	t_rgb		pixel_color = make_rgb(0,0,0);
	t_rayinfo	info;
	t_object	closest;
	t_rgb		objColor;
	t_vec3		normal;

	info = raycast(ray, scene);
	if (info.hitid == -1)
		return (skybox);
	
	closest = *(t_object *)vector_get_idx(&(scene->vobject), info.hitid);
	if (closest.type == PLANE)
	{
		objColor = uv_texture_plane(info.hitpos, &(scene->checker));
		normal = uv_normal_plane(info.hitpos, &(scene->normal));
	}
	else
	{
		objColor = closest.albedo;
		normal = info.hitnorm;
	}
	normal = info.hitnorm;
	pixel_color = ambient_color(objColor, scene->ambient);

	for (int i = 0; i < scene->vlight.size; ++i) {
		t_light	light = *(t_light *)vector_get_idx(&(scene->vlight), i);
		if (is_shadowed(&info, &light, scene) == TRUE)
			continue;
		pixel_color = vec3_plus_vec3(pixel_color, diffuse_color(&info, objColor, normal, &light));
		pixel_color = vec3_plus_vec3(pixel_color, specular_color(&ray, &info, objColor, normal, &light));
	}
	if (depth < RECURSIVE_MAX) {
		t_vec3 pos = vec3_plus_vec3(info.hitpos, vec3_multiply_num(normal, 0.01));
		t_vec3 reflect_dir = reflect_vec3(ray.direction, normal);
		t_ray reflect = make_ray(pos, reflect_dir, 1000);
		pixel_color = vec3_plus_vec3(pixel_color, vec3_multiply_num(trace_ray(reflect, scene, depth + 1), 0.9));

		t_vec3 refract_dir = refract_vec3(ray.direction, normal, 0.5, 0.5);
		t_ray refract = make_ray(pos, refract_dir, 1000);
		pixel_color = vec3_plus_vec3(pixel_color, vec3_multiply_num(trace_ray(refract, scene, depth + 1), 0.1));
	}
	clamp_vec3(&pixel_color, 0, 255);
	return (pixel_color);
}
