/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/18 13:16:21 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"
#include "math.h"

#define INIT_YAW -90
#define INIT_PITCH 0

#define MOVE_OFFSET 10.0
#define ROT_OFFSET M_PI / 24

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	front;		//z-axis
	t_vec3	up;			//y-axis
	t_vec3	right;		//x-axis
	double	yaw;		//y-axis angle
	double	pitch;		//x-axis angle
	//view transformation
	double	vmatrix[4][4];
	//projection
	double	pmatrix[4][4];
	//view -> projection
	double	pvmatrix[4][4];
	double 	fov;
	double 	near;
	double 	far;
}	t_camera;

void	init_camera(t_camera* camera);
void	translate_camera(t_camera* camera, int keycode);
void	rotate_camera(t_camera* camera, int keycode);
void	update_rotation_state(t_camera* camera);
void	update_vmatrix(t_camera* camera);
void	update_pmatrix(t_camera* camera);
void	update_pvmatrix(t_camera* camera);

#endif