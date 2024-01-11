/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by jihwjeon          #+#    #+#             */
/*   Updated: 2023/12/31 01:09:40 by singeonho        ###   ########.fr       */
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
		return (1);
	if (str_to_vec3(&pos, words[1]) != 0
		||str_to_vec3(&dir, words[2]) != 0)
		return (1);
	fov = ft_atod(words[3]);
	camera_constructor(&scene->camera, pos, dir, fov);
	return (0);
}

int	set_light(t_scene *scene, char **words)
{
	t_vec3	pos;
	t_rgb	albedo;
	float	brightness;

	if (words[1] == NULL || words[2] == NULL || words[3] == NULL
		|| words[4] != NULL)
		return (1);
	if (str_to_vec3(&pos, words[1]) != 0
		|| str_to_rgb(&albedo, words[3]) != 0)
		return (1);
	brightness = ft_atod(words[2]);
	scene->light = make_light(pos, albedo, brightness);
	return (0);
}
