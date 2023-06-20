/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/06/20 18:11:47 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"
#include "math.h"
#include "matrix.h"

#include <stdio.h>

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

void	init_camera(t_camera* camera)
{
	camera->position = make_vec3(0.0, 0.0, 50.0);
	camera->front = make_vec3(0.0, 0.0, -1.0);
	camera->up = make_vec3(0.0, 1.0, 0.0);
	camera->right = make_vec3(1.0, 0.0, 0.0);
	camera->yaw = INIT_YAW;
	camera->pitch = INIT_PITCH;
	camera->fov = 14.28;
	camera->near = 1.0;
	camera->far = 1000.0;
	update_vmatrix(camera);
	update_pmatrix(camera);
}

void	translate_camera(t_camera* camera, int keycode)
{
	t_vec3	tvec3;
	
	if (keycode == KEY_W)
		tvec3 = make_vec3(camera->front.x * MOVE_OFFSET, camera->front.y * MOVE_OFFSET, camera->front.z * MOVE_OFFSET);
	else if (keycode == KEY_S)
		tvec3 = make_vec3(-camera->front.x * MOVE_OFFSET, -camera->front.y * MOVE_OFFSET, -camera->front.z * MOVE_OFFSET);
	else if (keycode == KEY_A)
		tvec3 = make_vec3(-camera->right.x * MOVE_OFFSET, -camera->right.y * MOVE_OFFSET, -camera->right.z * MOVE_OFFSET);
	else if (keycode == KEY_D)
		tvec3 = make_vec3(camera->right.x * MOVE_OFFSET, camera->right.y * MOVE_OFFSET, camera->right.z * MOVE_OFFSET);
	camera->position.x += tvec3.x;
	camera->position.y += tvec3.y;
	camera->position.z += tvec3.z;
	update_vmatrix(camera);
}

void	rotate_camera(t_camera* camera, int keycode)
{
	if (keycode == KEY_O)
		camera->pitch += ROT_OFFSET;
	else if (keycode == KEY_L)
		camera->pitch -= ROT_OFFSET;
	else if (keycode == KEY_K)
		camera->yaw += ROT_OFFSET;
	else if (keycode == KEY_COLON)
		camera->yaw -= ROT_OFFSET;
	update_rotation_state(camera);
	update_vmatrix(camera);
}

void	update_rotation_state(t_camera* camera)
{
	const t_vec3 UP = make_vec3(0.0, 1.0, 0.0);
	t_vec3	nfront;
	
	nfront.x = cos(camera->yaw) * cos(camera->pitch);
	nfront.y = sin(camera->pitch);
	nfront.z = sin(camera->yaw) * cos(camera->pitch);
	camera->front = make_vec3(nfront.x, nfront.y, nfront.z);
	camera->right = cross_product(camera->front, UP);
	normalize_vec3(&(camera->right));
	camera->up = cross_product(camera->right, camera->front);
	normalize_vec3(&(camera->up));
}

void	update_vmatrix(t_camera* camera)
{
	double	rmatrix[4][4];
	double	tmatrix[4][4];

	init_identity_mat4(&(rmatrix));
	rmatrix[0][0] = camera->right.x, rmatrix[0][1] = camera->right.y, rmatrix[0][2] = camera->right.z;
	rmatrix[1][0] = camera->up.x, rmatrix[1][1] = camera->up.y, rmatrix[1][2] = camera->up.z;
	rmatrix[2][0] = camera->front.x, rmatrix[2][1] = camera->front.y, rmatrix[2][2] = camera->front.z;
	
	init_identity_mat4(&(tmatrix));
	tmatrix[0][3] = -camera->position.x, tmatrix[1][3] = -camera->position.y, tmatrix[2][3] = -camera->position.z;
	
	multiply_mat4_to_mat4(&(rmatrix), &(tmatrix), &(camera->vmatrix));
}

void	update_pmatrix(t_camera* camera)
{
	double	aspect = 1920 / 1080;

	camera->pmatrix[0][0] = 1.0 / (tan(camera->fov / 2.0) * aspect);
	camera->pmatrix[1][1] = 1.0 / (tan(camera->fov / 2.0));
	camera->pmatrix[2][2] = -(camera->far + camera->near) / (camera->far - camera->near);
	camera->pmatrix[2][3] = -(2.0 * camera->far * camera->near) / (camera->far - camera->near);
	camera->pmatrix[3][2] = -1.0;
	camera->pmatrix[3][3] = 0.0;
	update_pvmatrix(camera);
}

void	update_pvmatrix(t_camera* camera)
{
	double	temp[4][4];
	int		rptr;
	int		cptr;
	int		ptr;

	init_identity_mat4(&temp);
	rptr = -1;
	while (++rptr < 4)
	{
		cptr = -1;
		while (++cptr < 4)
		{
			ptr = -1;
			while (++ptr < 4)
				temp[rptr][cptr] += camera->pmatrix[rptr][ptr] * camera->vmatrix[ptr][cptr];
			if (rptr == cptr)
				temp[rptr][cptr]--;
		}
	}
	copy_mat4(&(camera->pvmatrix), &temp);
}