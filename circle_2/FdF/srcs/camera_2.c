/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:06:27 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 15:17:25 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "controller.h"

void	switch_camera_mode(t_camera *camera)
{
	if (camera->camera_mode == ORTHOGRAPHIC)
		camera->camera_mode = PERSPECTIVE;
	else if (camera->camera_mode == PERSPECTIVE)
		camera->camera_mode = ORTHOGRAPHIC;
}

void	translate_camera(t_camera *camera, int keycode)
{
	t_vec3	offset;

	if (keycode == KEY_W)
		offset = make_vec3(-camera->basis_n.x,
				-camera->basis_n.y,
				-camera->basis_n.z);
	else if (keycode == KEY_S)
		offset = make_vec3(camera->basis_n.x,
				camera->basis_n.y,
				camera->basis_n.z);
	else if (keycode == KEY_A)
		offset = make_vec3(-camera->basis_u.x,
				-camera->basis_u.y,
				-camera->basis_u.z);
	else if (keycode == KEY_D)
		offset = make_vec3(camera->basis_u.x,
				camera->basis_u.y,
				camera->basis_u.z);
	camera->position.x += offset.x;
	camera->position.y += offset.y;
	camera->position.z += offset.z;
}

void	zoom_camera(t_camera *camera, int keycode)
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
		if (camera->fov > M_PI_2 + M_PI_3)
			camera->fov = M_PI_2 + M_PI_3;
	}	
}
