/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:38:32 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 13:10:21 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eventcode.h"
#include <stdio.h>
#include "camera.h"

void	camera_rotate(t_camera *camera, int dx, int dy)
{
	if (camera->is_movable == FALSE)
		return;
	t_vec3	right = cross_vec3(camera->forward, updir);
	t_vec3	up = cross_vec3(right, camera->forward);

	t_quat q = normalize_quat(cross_quat(angle_axis(-dy * MOUSE_SENSITIVE, right), angle_axis(-dx * MOUSE_SENSITIVE, up)));
	camera->forward = normalize_vec3(rotate_vec3(q, camera->forward));

	camera->view = make_view_mat(camera->position, vec3_plus_vec3(camera->position, camera->forward), updir);
	camera->iview = inv_mat4(camera->view);
	camera->proj = make_proj_mat(camera->fov, camera->aspect, camera->near, camera->far);
	camera->iproj = inv_mat4(camera->proj);
	calc_raydirs(camera);
}

void	camera_translate(t_camera *camera, int key)
{
	if (camera->is_movable == FALSE)
		return;
	t_vec3	right = cross_vec3(camera->forward, updir);
	if (key == KEY_W)
		camera->position = vec3_plus_vec3(camera->position,
			vec3_multiply_num(camera->forward, MOVE_SPEED));
	else if (key == KEY_S)
		camera->position = vec3_plus_vec3(camera->position,
			vec3_multiply_num(camera->forward, -MOVE_SPEED));
	else if (key == KEY_A)
		camera->position = vec3_plus_vec3(camera->position,
			vec3_multiply_num(right, -MOVE_SPEED));
	else if (key == KEY_D)
		camera->position = vec3_plus_vec3(camera->position,
			vec3_multiply_num(right, MOVE_SPEED));

	camera->view = make_view_mat(camera->position, vec3_plus_vec3(camera->position, camera->forward), updir);
	camera->iview = inv_mat4(camera->view);
}

void	camera_mode_change(t_camera *camera, int key)
{
	if (key == KEY_1)
	{
		camera->is_movable = FALSE;
		camera->k = 1;
	}
	else if (key == KEY_2)
	{
		camera->is_movable = TRUE;
		camera->k = 3;	
	}
	calc_raydirs(camera);
}