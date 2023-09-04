/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/09/05 00:54:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"
#include "math.h"
#include "matrix.h"

static void	update_camera_coordinate(t_camera* camera)
{
	camera->direction.x = cos(camera->pitch) * cos(camera->yaw);
	camera->direction.y = sin(camera->pitch);
	camera->direction.z = cos(camera->pitch) * sin(camera->yaw);
	normalize_vec3(&(camera->direction));
	camera->basis_u = cross_product(camera->direction, camera->worldup);
	normalize_vec3(&(camera->basis_u));
	camera->basis_v = cross_product(camera->basis_u, camera->direction);
	normalize_vec3(&(camera->basis_v));
}

void	init_camera(t_camera* camera)
{
	camera->position = make_vec3(100.0, 100.0, 100.0);
	camera->worldup = make_vec3(0.0, 1.0, 0.0);

	camera->yaw = INIT_YAW;
	camera->pitch = INIT_PITCH;
	update_camera_coordinate(camera);

	camera->near = 1.0;
	camera->far = 1000.0;
	camera->left = -500.0;
	camera->right = 500.0;
	camera->bottom = -500.0;
	camera->top = 500.0;

	camera->aspect = 1920 / 1080;
	camera->fovx = 1.57;
	camera->fovy = 1.0297;
	
	camera->projection_type = orthographic;
}

void	switch_camera_mode(t_camera* camera)
{
	if (camera->projection_type == orthographic)
		camera->projection_type = perspective;
	else if (camera->projection_type == perspective)
		camera->projection_type = orthographic;
}

void	translate_camera(t_camera* camera, int keycode)
{
	t_vec3	offset;

	if (keycode == KEY_W)
		offset = make_vec3(camera->direction.x * MOVE_OFFSET,
		 camera->direction.y * MOVE_OFFSET,
		 camera->direction.z * MOVE_OFFSET);
	else if (keycode == KEY_S)
		offset = make_vec3(-camera->direction.x * MOVE_OFFSET,
		 -camera->direction.y * MOVE_OFFSET,
		 -camera->direction.z * MOVE_OFFSET);
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
		camera->pitch += ROT_OFFSET;
		if (camera->pitch > M_PI_2)
			camera->pitch = M_PI_2 - 0.001;
	}	
	else if (keycode == KEY_L)
	{
		camera->pitch -= ROT_OFFSET;
		if (camera->pitch < -M_PI_2)
			camera->pitch = -M_PI_2 + 0.001;
	}
	else if (keycode == KEY_K)
	{
		camera->yaw += ROT_OFFSET;
		if (camera->yaw > 2 * M_PI)
			camera->yaw -= 2 * M_PI;
	}	
	else if (keycode == KEY_COLON)
	{
		camera->yaw -= ROT_OFFSET;	
		if (camera->yaw < -2 * M_PI)
			camera->yaw += 2 * M_PI;
	}
	update_camera_coordinate(camera);
}

void	zoom_camera(t_camera* camera, int keycode)
{
	if (keycode == KEY_Q)
		camera->near -= ZOOM_OFFSET;
	else if (keycode == KEY_E)
		camera->near += ZOOM_OFFSET;
}