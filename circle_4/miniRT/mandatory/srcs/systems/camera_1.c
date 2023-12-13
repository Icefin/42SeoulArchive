/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:44:26 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 15:22:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	initialize_camera(t_camera *camera)
{
	t_vec3	position;
	t_vec3	rotation;
	t_vec3	forward;

	position = make_vec3(0.0, 0.0, 0.0);
	rotation = make_vec3(0.0, 0.0, 0.0);
	
	camera->transform.position = position;
	camera->transform.rotation = rotation;
	camera->fov = 45.0;
	camera->near = 0.1;
	camera->far = 100.0;

	forward = get_forward_direction(&(rotation));
	camera->view = make_view_mat(camera->transform.position, forward, updir);
	camera->iview = inv_mat4(&(camera->view));
	camera->proj = make_proj_mat(camera->fov, camera->aspect, camera->near, camera->far);
	camera->iproj = inv_mat4(&(camera->proj));
	calc_raydirs(camera);
}

void	destroy_camera(t_camera *camera)
{
	vector_destructor(&(camera->raydirs));
}

void	camera_on_update(t_camera *camera)
{
	t_bool	is_moved;

	is_moved = FALSE;
	//check keyboard input
	//check mouse movement

	if (is_moved == TRUE)
	{
		calc_raydirs(camera);
	}
}

void	camera_on_resize(t_camera *camera, t_uint32 width, t_uint32 height)
{
	camera->width = width;
	camera->height = height;
	calc_raydirs(camera);
}