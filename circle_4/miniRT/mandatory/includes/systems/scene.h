/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:05:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/18 15:58:40 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "vector.h"

typedef struct s_scene
{
	t_camera	camera;
	t_vector	objects;
	t_vector	lights;
}	t_scene;

void	initialize_scene(t_scene *scene);
void	destroy_scene(t_scene *scene);

#endif