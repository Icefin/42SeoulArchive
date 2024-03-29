/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:07 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "rtmath.h"
#include "camera.h"
#include "light.h"
#include "scene.h"

int	str_to_vec3(t_vec3 *pos, char *str);
int	str_to_rgb(t_rgb *rgb, char *str);

void	ft_free_2d_char(char **words)
{
	int	idx;

	if (words != NULL)
	{
		idx = 0;
		while (words[idx] != NULL)
			free(words[idx++]);
		free(words);
	}
}

int	set_ambient(t_scene *scene, char **words)
{
	t_rgb	ambient;
	double	lighting_ratio;

	if (words[1] == NULL || words[2] == NULL
		|| words[3] != NULL)
		return (1);
	lighting_ratio = ft_atod(words[1]);
	if (str_to_rgb(&ambient, words[2]) != 0)
		return (1);
	scene->ambient = vec3_multiply_num(ambient, lighting_ratio);
	return (0);
}

int	set_camera(t_scene *scene, char **words)
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] != NULL)
		return (2);
	if (str_to_vec3(&pos, words[1]) != 0
		||str_to_vec3(&dir, words[2]) != 0)
		return (2);
	fov = ft_atod(words[3]);
	camera_constructor(&scene->camera, pos, dir, fov);
	return (0);
}

int	set_light(t_scene *scene, char **words)
{
	t_light	light;
	t_vec3	pos;
	t_rgb	albedo;
	float	brightness;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] != NULL)
		return (3);
	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_rgb(&albedo, words[3]) != 0)
		return (3);
	brightness = ft_atod(words[2]);
	light = make_light(pos, albedo, brightness);
	vector_push_back(&scene->vlight, (void *)&light);
	return (0);
}
