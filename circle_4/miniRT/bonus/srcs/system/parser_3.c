/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:23 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:25 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rtmath.h"
#include "scene.h"
#include "vector.h"
#include "object.h"

int	str_to_vec3(t_vec3 *pos, char *str);
int	str_to_rgb(t_rgb *rgb, char *str);

int	set_sphere(t_scene *scene, char **words, int id)
{
	t_vec3		pos;
	t_rgb		albedo;
	float		radius;
	t_object	sphere;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] != NULL)
		return (1);
	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_rgb(&albedo, words[3]) != 0)
		return (4);
	radius = ft_atod(words[2]);
	sphere = make_sphere(pos, albedo, radius);
	sphere.id = id;
	if (sphere.radius <= 0
		|| (sphere.albedo.r < 0 || sphere.albedo.r > 255)
		|| (sphere.albedo.g < 0 || sphere.albedo.g > 255)
		|| (sphere.albedo.b < 0 || sphere.albedo.b > 255))
		return (4);
	vector_push_back(&scene->vobject, (void *)&sphere);
	return (0);
}

int	set_plane(t_scene *scene, char **words, int id)
{
	t_vec3		pos;
	t_rgb		albedo;
	t_vec3		normal;
	t_object	plane;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] != NULL)
		return (5);
	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_vec3(&normal, words[2]) != 0
		|| str_to_rgb(&albedo, words[3]) != 0)
		return (5);
	plane = make_plane(pos, albedo, normal);
	plane.id = id;
	if ((plane.albedo.r < 0 || plane.albedo.r > 255)
		|| (plane.albedo.g < 0 || plane.albedo.g > 255)
		|| (plane.albedo.b < 0 || plane.albedo.b > 255)
		|| (plane.normal.x < -1 || plane.normal.x > 1)
		|| (plane.normal.y < -1 || plane.normal.y > 1)
		|| (plane.normal.z < -1 || plane.normal.z > 1))
		return (5);
	vector_push_back(&scene->vobject, (void *)&plane);
	return (0);
}

int	set_cylinder_2(char **words, t_object *cy, float diameter, float length)
{
	t_vec3	pos;
	t_vec3	axis;
	t_rgb	albedo;

	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_vec3(&axis, words[2]) != 0
		|| str_to_rgb(&albedo, words[5]) != 0)
		return (1);
	*cy = make_cylinder(pos, albedo, diameter / 2, axis, length);
	return (0);
}

int	set_cylinder(t_scene *scene, char **words, int id)
{
	float		diameter;
	float		length;
	t_object	cylinder;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] == NULL || words[5] == NULL || words[6] != NULL)
		return (6);
	diameter = ft_atod(words[3]);
	length = ft_atod(words[4]);
	if (set_cylinder_2(words, &cylinder, diameter, length) != 0)
		return (6);
	cylinder.id = id;
	if (cylinder.radius <= 0 || cylinder.length <= 0
		|| (cylinder.albedo.r < 0 || cylinder.albedo.r > 255)
		|| (cylinder.albedo.g < 0 || cylinder.albedo.g > 255)
		|| (cylinder.albedo.b < 0 || cylinder.albedo.b > 255)
		|| (cylinder.axis.x < -1 || cylinder.axis.x > 1)
		|| (cylinder.axis.y < -1 || cylinder.axis.y > 1)
		|| (cylinder.axis.z < -1 || cylinder.axis.z > 1))
		return (6);
	vector_push_back(&scene->vobject, (void *)&cylinder);
	return (0);
}
