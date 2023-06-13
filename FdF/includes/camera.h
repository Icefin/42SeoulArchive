/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 16:00:41 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

#define CAMERA_INIT_X 0
#define CAMERA_INIT_Y 0
#define CAMERA_INIT_Z 1

#define CAMERA_INIT_G_X 0
#define CAMERA_INIT_G_Y 0
#define CAMERA_INIT_G_Z -1

typedef struct s_camera
{
	t_vec3 position;
	t_vec3 gaze;
}	t_camera;

void	init_camera(t_camera* camera);
void	translate_camera(t_camera* camera, t_vec3 pos);
void	rotate_camera(t_camera* camera, t_vec3 ang);

#endif