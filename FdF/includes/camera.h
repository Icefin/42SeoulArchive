/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/12 17:42:25 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"

#define CAMERA_INIT_X 100
#define CAMERA_INIT_Y 100
#define CAMERA_INIT_Z 100

#define CAMERA_INIT_G_X -0.577
#define CAMERA_INIT_G_Y -0.577
#define CAMERA_INIT_G_Z -0.577

typedef struct s_camera
{
	t_vec3 position;
	t_vec3 gaze;
}	t_camera;

void	translate_camera(t_camera* camera, t_vec3 pos);
void	rotate_camera(t_camera* camera, t_vec3 ang);

#endif