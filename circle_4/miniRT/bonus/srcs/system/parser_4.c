/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:29:18 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:43 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "rtmath.h"
#include "scene.h"
#include "vector.h"
#include "object.h"

int	str_to_vec3(t_vec3 *pos, char *str);
int	str_to_rgb(t_rgb *rgb, char *str);

int	set_cone_2(char **words, t_object *cone, float cos_a, float length)
{
	t_vec3	pos;
	t_vec3	axis;
	t_rgb	albedo;

	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_vec3(&axis, words[2]) != 0
		|| str_to_rgb(&albedo, words[5]) != 0)
		return (1);
	*cone = make_cone(pos, albedo, cos_a, axis, length);
	return (0);
}

int	set_cone(t_scene *scene, char **words, int id)
{
	float		cos_a;
	float		length;
	t_object	cone;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] == NULL || words[5] == NULL || words[6] != NULL)
		return (7);
	cos_a = ft_atod(words[3]);
	length = ft_atod(words[4]);
	if (set_cone_2(words, &cone, cos_a, length) != 0)
		return (7);
	cone.id = id;
	if (cone.length <= 0 || (cone.cos_a <= 0 || cone.cos_a >=1) 
		|| (cone.albedo.r < 0 || cone.albedo.r > 255)
		|| (cone.albedo.g < 0 || cone.albedo.g > 255)
		|| (cone.albedo.b < 0 || cone.albedo.b > 255)
		|| (cone.axis.x < -1 || cone.axis.x > 1)
		|| (cone.axis.y < -1 || cone.axis.y > 1)
		|| (cone.axis.z < -1 || cone.axis.z > 1))
		return (7);
	cone.radius = (cone.length / cone.cos_a) * sqrt((1 - pow(cone.cos_a, 2.0)));
	vector_push_back(&scene->vobject, (void *)&cone);
	return (0);
}

int	set_triangle(t_scene *scene, char **words, int id)
{
	t_object	triangle;
	t_vec3		t1;
	t_vec3		t2;
	t_vec3		t3;
	t_rgb		albedo;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] == NULL || words[5] != NULL)
		return (8);
	if (str_to_vec3(&t1, words[1]) != 0
		|| str_to_vec3(&t2, words[2]) != 0
		|| str_to_vec3(&t3, words[3]) != 0
		|| str_to_rgb(&albedo, words[4]) != 0)
		return (8);
	triangle = make_triangle(t1, t2, t3, albedo);
	triangle.id = id;
	vector_push_back(&scene->vobject, (void *)&triangle);
	return (0);
}