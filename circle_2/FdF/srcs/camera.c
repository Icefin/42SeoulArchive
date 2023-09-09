/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 15:37:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"
#include "math.h"
#include "matrix.h"

static void	update_camera_coordinate(t_camera* camera)
{
	t_vec3 front;

	front.x = cos(camera->pitch) * cos(camera->yaw);
	front.y = sin(camera->pitch);
	front.z = cos(camera->pitch) * sin(camera->yaw);
	camera->basis_n.x = -front.x;
	camera->basis_n.y = -front.y;
	camera->basis_n.z = -front.z;
	normalize_vec3(&(camera->basis_n));
	camera->basis_u = cross_product(camera->worldup, camera->basis_n);
	normalize_vec3(&(camera->basis_u));
	camera->basis_v = cross_product(camera->basis_n, camera->basis_u);
	normalize_vec3(&(camera->basis_v));
}

void	init_camera(t_camera* camera)
{
	camera->position = make_vec3(100.0, 100.0, 100.0);
	camera->worldup = make_vec3(0.0, 1.0, 0.0);

	camera->yaw = INIT_YAW;
	camera->pitch = INIT_PITCH;
	update_camera_coordinate(camera);

	camera->near = 0.1;
	camera->far = 1000.0;
	camera->left = -500.0;
	camera->right = 500.0;
	camera->bottom = -500.0;
	camera->top = 500.0;

	camera->aspect = 1024 / 768;
	camera->fov = M_PI_2;
	 
	camera->camera_mode = orthographic;
}

void	switch_camera_mode(t_camera* camera)
{
	if (camera->camera_mode == orthographic)
		camera->camera_mode = perspective;
	else if (camera->camera_mode == perspective)
		camera->camera_mode = orthographic;
}

void	translate_camera(t_camera* camera, int keycode)
{
	t_vec3	offset;

	if (keycode == KEY_W)
		offset = make_vec3(-camera->basis_n.x * MOVE_OFFSET,
		 -camera->basis_n.y * MOVE_OFFSET,
		 -camera->basis_n.z * MOVE_OFFSET);
	else if (keycode == KEY_S)
		offset = make_vec3(camera->basis_n.x * MOVE_OFFSET,
		 camera->basis_n.y * MOVE_OFFSET,
		 camera->basis_n.z * MOVE_OFFSET);
	else if (keycode == KEY_A)
		offset = make_vec3(-camera->basis_u.x * MOVE_OFFSET,
		 -camera->basis_u.y * MOVE_OFFSET,
		 -camera->basis_u.z * MOVE_OFFSET);
	else if (keycode == KEY_D)
		offset = make_vec3(camera->basis_u.x * MOVE_OFFSET,
		 camera->basis_u.y * MOVE_OFFSET,
		 camera->basis_u.z * MOVE_OFFSET);

	camera->position.x += offset.x;
	camera->position.y += offset.y;
	camera->position.z += offset.z;
}

void	rotate_camera(t_camera* camera, int keycode)
{
	if (keycode == KEY_O)
	{
		camera->pitch += M_PI_36;
		if (camera->pitch > M_PI_2)
			camera->pitch = M_PI_2 - 0.001;
	}	
	else if (keycode == KEY_L)
	{
		camera->pitch -= M_PI_36;
		if (camera->pitch < -M_PI_2)
			camera->pitch = -M_PI_2 + 0.001;
	}
	else if (keycode == KEY_K)
	{
		camera->yaw -= M_PI_36;	
		if (camera->yaw < -2 * M_PI)
			camera->yaw += 2 * M_PI;
	}	
	else if (keycode == KEY_COLON)
	{
		
		camera->yaw += M_PI_36;
		if (camera->yaw > 2 * M_PI)
			camera->yaw -= 2 * M_PI;
	}
	update_camera_coordinate(camera);
}

void	zoom_camera(t_camera* camera, int keycode)
{
	if (keycode == KEY_Q)
	{
		camera->fov -= M_PI_72;
		if (camera->fov < M_PI_6)
			camera->fov = M_PI_6;
	}
	else if (keycode == KEY_E)
	{
		camera->fov += M_PI_72;
		if (camera->fov > M_PI_3)
			camera->fov =  M_PI_3;
	}	
}