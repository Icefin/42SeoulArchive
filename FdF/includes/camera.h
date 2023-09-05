/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/09/05 13:22:27 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"
#include "math.h"

#define INIT_YAW M_PI_4
#define INIT_PITCH -0.615472907

#define MOVE_OFFSET 30.0
#define M_PI_3 (M_PI / 3)
#define M_PI_6 (M_PI / 6)
#define M_PI_36 (M_PI / 36)
#define M_PI_72 (M_PI / 72)

typedef enum e_projection_type
{
	orthographic = 0,
	perspective
}	t_projection_type;

typedef struct s_camera
{
	t_vec3 position;
	t_vec3 direction;
	t_vec3 basis_u;
	t_vec3 basis_v;
	t_vec3 worldup;
	
	double yaw;
	double pitch;

	double near;
	double far;
	double left;
	double right;
	double bottom;
	double top;

	double aspect;
	double fov;
	
	t_projection_type camera_mode;
}	t_camera;

void	init_camera(t_camera* camera);
void	switch_camera_mode(t_camera* camera);
void	translate_camera(t_camera* camera, int keycode);
void	rotate_camera(t_camera* camera, int keycode);
void	zoom_camera(t_camera* camera, int keycode);

#endif