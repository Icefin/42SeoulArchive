/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/06/17 15:07:00 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"
#include "math.h"
#include "matrix.h"

#include <stdio.h>

static void	test_camera_state_print(t_camera* camera) {
	printf("camera Position :\n");
	printf("{%f, %f, %f, %f}\n", camera->position.x, camera->position.y, camera->position.z, camera->position.w);
	printf("Camera Space : \n");
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			printf("%f ", camera->basis[r][c]);
		}
		printf("\n");
	}
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
	camera->position = make_vec4(10.0, 10.0, 0.0, 1.0);
	init_identity_mat4(&(camera->basis));
	init_identity_mat4(&(camera->pmatrix));
	camera->fov = 14.28;
	camera->near = 1.0;
	camera->far = 1000.0;
	update_vmatrix(camera);
	//update_pmatrix(camera);
}

void	translate_camera(t_camera* camera, int keycode)
{
	t_vec4	tvec4;
	
	tvec4 = make_vec4(0.0, 0.0, 0.0, 0.0);
	if (keycode == KEY_W)
		tvec4.z = -MOVE_OFFSET;
	else if (keycode == KEY_S)
		tvec4.z = MOVE_OFFSET;
	else if (keycode == KEY_A)
		tvec4.x = -MOVE_OFFSET;
	else if (keycode == KEY_D)
		tvec4.x = MOVE_OFFSET;
	tvec4 = multiply_mat4_to_vec4(&(camera->basis), tvec4);
	camera->position.x += tvec4.x;
	camera->position.y += tvec4.y;
	camera->position.z += tvec4.z;
	update_vmatrix(camera);
}

void	rotate_camera(t_camera* camera, int keycode)
{
	double	rmatrix[4][4];

	init_identity_mat4(&rmatrix);
	if (keycode == KEY_O || keycode == KEY_L)
	{
		rmatrix[1][1] = cos(ROT_OFFSET);
		rmatrix[2][2] = rmatrix[1][1];
		rmatrix[1][2] = -sin(ROT_OFFSET);
		rmatrix[2][1] = -rmatrix[1][2];
	}
	if (keycode == KEY_L)
	{
		rmatrix[1][2] = -rmatrix[1][2];
		rmatrix[2][1] = -rmatrix[2][1];
	}	
	if (keycode == KEY_K || keycode == KEY_COLON)
	{
		rmatrix[0][0] = cos(ROT_OFFSET);
		rmatrix[2][2] = rmatrix[0][0];
		rmatrix[0][2] = sin(ROT_OFFSET);
		rmatrix[2][0] = -rmatrix[0][2];
	}
	if (keycode == KEY_COLON)
	{
		rmatrix[0][2] = -rmatrix[0][2];	
		rmatrix[2][0] = -rmatrix[2][0];
	}
	multiply_mat4_to_mat4(&(rmatrix), &(camera->basis));
	update_vmatrix(camera);
}

void	update_vmatrix(t_camera* camera)
{
	double	tmatrix[4][4];
	double	rmatrix[4][4];

	init_identity_mat4(&tmatrix);
	tmatrix[0][3] = -camera->position.x;
	tmatrix[1][3] = -camera->position.y;
	tmatrix[2][3] = -camera->position.z;
	
	copy_mat4(&rmatrix, &(camera->basis));
	double temp = rmatrix[0][1];
	rmatrix[0][1] = rmatrix[1][0];
	rmatrix[1][0] = temp;
	temp = rmatrix[0][2];
	rmatrix[0][2] = rmatrix[2][0];
	rmatrix[2][0] = temp;
	temp = rmatrix[2][1];
	rmatrix[2][1] = rmatrix[1][2];
	rmatrix[1][2] = temp;
	multiply_mat4_to_mat4(&(rmatrix), &(tmatrix));
	copy_mat4(&(camera->vmatrix), (&rmatrix));
	update_pvmatrix(camera);
	test_camera_state_print(camera);
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