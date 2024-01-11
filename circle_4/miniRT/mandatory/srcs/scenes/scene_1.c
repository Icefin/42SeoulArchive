/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:23:02 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/31 01:11:17 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "rtmath.h"

extern void	init_scene_from_file(t_scene *scene, char *file);

void	scene_constructor(t_scene *scene, char *file)
{
	vector_constructor(&scene->vobject, 10, sizeof(t_object));
	init_scene_from_file(scene, file);
}

void	scene_destructor(t_scene *scene)
{
	vector_destructor(&(scene->vobject));
	camera_destructor(&(scene->camera));
}
