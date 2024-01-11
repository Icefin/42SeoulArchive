/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:23:02 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 14:41:21 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "rtmath.h"

extern void	init_scene_from_file(t_scene *scene, char *file);

void	scene_constructor(t_scene *scene, char *file)
{
	vector_constructor(&scene->vlight, 10, sizeof(t_light));
	vector_constructor(&scene->vobject, 10, sizeof(t_object));
	init_scene_from_file(scene, file);
}

void	scene_destructor(t_scene *scene)
{
	vector_destructor(&(scene->vobject));
	camera_destructor(&(scene->camera));
}
