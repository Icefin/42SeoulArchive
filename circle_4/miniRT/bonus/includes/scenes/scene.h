/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:00 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/07 16:38:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rtmath.h"
# include "camera.h"
# include "object.h"
# include "vector.h"
# include "light.h"
# include "texture.h"

typedef struct s_scene
{
	t_camera	camera;

	t_rgb		ambient;
	t_vector	vlight;
	t_vector	vobject;

	t_texture	checker;
	t_texture	normal;
}	t_scene;

void	scene_constructor(t_scene *scene, char *file);
void	scene_destructor(t_scene *scene);

#endif