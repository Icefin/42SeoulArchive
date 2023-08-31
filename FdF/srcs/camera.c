/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/08/31 18:12:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"
#include "math.h"
#include "matrix.h"

#include <stdio.h>

#ifdef DEBUG_MODE
void	test_camera_state_print(t_camera* camera) {
	printf("camera Position :\n");
	printf("{%f, %f, %f}\n", camera->position.x, camera->position.y, camera->position.z);
	printf("Camera VMatrix : \n");
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			printf("%f ", camera->vmatrix[r][c]);
		}
		printf("\n");
	}
}
#endif

void	init_camera(t_camera* camera)
{
	camera->position = make_vec3(0.0, 0.0, 0.0);
	camera->worldup = make_vec3(0.0, 1.0, 0.0);

	camera->yaw = INIT_YAW;
	camera->pitch = INIT_PITCH;
	update_rotation_state(camera);
	
	camera->zoom = 1.0f;

	camera->fov = 14.28;
	camera->near = 1.0;
	camera->far = 1000.0;
	
	camera->isPerspectiveMode = 0;

	update_vmatrix(camera);
	update_pmatrix(camera);
	update_pvmatrix(camera);
}

void	switch_camera_mode(t_camera* camera)
{
	camera->isPerspectiveMode = (camera->isPerspectiveMode == 0) ? 1 : 0;
}

void	translate_camera(t_camera* camera, int keycode)
{
	t_vec3	tvec3;
	
	if (keycode == KEY_W)
		tvec3 = make_vec3(camera->direction.x * MOVE_OFFSET,
		 camera->direction.y * MOVE_OFFSET,
		 camera->direction.z * MOVE_OFFSET);
	else if (keycode == KEY_S)
		tvec3 = make_vec3(-camera->direction.x * MOVE_OFFSET,
		 -camera->direction.y * MOVE_OFFSET,
		 -camera->direction.z * MOVE_OFFSET);
	else if (keycode == KEY_A)
		tvec3 = make_vec3(-camera->right.x * MOVE_OFFSET,
		 -camera->right.y * MOVE_OFFSET,
		 -camera->right.z * MOVE_OFFSET);
	else if (keycode == KEY_D)
		tvec3 = make_vec3(camera->right.x * MOVE_OFFSET,
		 camera->right.y * MOVE_OFFSET,
		 camera->right.z * MOVE_OFFSET);

	camera->position.x += tvec3.x;
	camera->position.y += tvec3.y;
	camera->position.z += tvec3.z;

	update_vmatrix(camera);
	update_pvmatrix(camera);
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
	printf("Camera Value || Pitch : %f, Yaw : %f\n", camera->pitch, camera->yaw);
	update_rotation_state(camera);
	update_vmatrix(camera);
	update_pvmatrix(camera);
}

void	zoom_camera(t_camera* camera, int keycode)
{
	if (keycode == KEY_Q)
		camera->fov -= ZOOM_OFFSET;
	else if (keycode == KEY_E)
		camera->fov += ZOOM_OFFSET;
	
	update_pmatrix(camera);
	update_pvmatrix(camera);
}

void	update_rotation_state(t_camera* camera)
{
	t_vec3	ndirection;

	ndirection.x = cos(camera->yaw) * cos(camera->pitch);
	ndirection.y = sin(camera->pitch);
	ndirection.z = sin(camera->yaw) * cos(camera->pitch);
	camera->direction = ndirection;
	normalize_vec3(&(camera->direction));
	camera->right = cross_product(ndirection, camera->worldup);
	normalize_vec3(&(camera->right));
	camera->up = cross_product(camera->right, ndirection);
	normalize_vec3(&(camera->up));
}

void	update_vmatrix(t_camera* camera)
{
	double	rmatrix[4][4];
	double	tmatrix[4][4];

	init_identity_mat4(&(rmatrix));
	rmatrix[0][0] = camera->right.x;
	rmatrix[0][1] = camera->right.y;
	rmatrix[0][2] = camera->right.z;
	
	rmatrix[1][0] = camera->up.x;
	rmatrix[1][1] = camera->up.y;
	rmatrix[1][2] = camera->up.z;
	
	rmatrix[2][0] = -camera->direction.x;
	rmatrix[2][1] = -camera->direction.y;
	rmatrix[2][2] = -camera->direction.z;
	
	init_identity_mat4(&(tmatrix));
	tmatrix[0][3] = -camera->position.x;
	tmatrix[1][3] = -camera->position.y;
	tmatrix[2][3] = -camera->position.z;
	
	multiply_mat4_to_mat4(&(rmatrix), &(tmatrix), &(camera->vmatrix));
}

void	update_pmatrix(t_camera* camera)
{
	init_zero_mat4(&(camera->pmatrix));
	camera->pmatrix[0][0] = atan(camera->fov / 2.0);
	camera->pmatrix[1][1] = atan(camera->fov / 2.0);
	camera->pmatrix[2][2] = -(camera->far + camera->near) / (camera->far - camera->near);
	camera->pmatrix[2][3] = -(2.0 * camera->far * camera->near) / (camera->far - camera->near);
	camera->pmatrix[3][2] = -1.0;
}

void	update_pvmatrix(t_camera* camera)
{
	multiply_mat4_to_mat4(&(camera->pmatrix), &(camera->vmatrix), &(camera->pvmatrix));
}