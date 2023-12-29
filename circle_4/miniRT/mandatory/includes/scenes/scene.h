/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:55:00 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/20 17:15:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "rtmath.h"
# include "camera.h"
# include "object.h"
# include "vector.h"
# include "light.h"

typedef struct s_scene
{
	t_camera	camera;

	t_rgb		ambient;
	t_light		light;
	t_vector	vobject;
}	t_scene;

void	scene_constructor(t_scene *scene, char *file);
void	scene_destructor(t_scene *scene);

#endif