/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:44:26 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 18:58:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	initialize_camera(t_camera *camera, const t_vec3 *pos, const t_vec3 *dir, const double fov)
{	
	camera->position = *pos;
	camera->forward = *dir;
	camera->fov = fov;
	camera->near = 0.1;
	camera->far = 100.0;

	camera->view = make_view_mat(camera->position, camera->forward, updir);
	camera->iview = inv_mat4(&(camera->view));
	camera->proj = make_proj_mat(camera->fov, camera->aspect, camera->near, camera->far);
	camera->iproj = inv_mat4(&(camera->proj));
	calc_raydirs(camera);
}

void	destroy_camera(t_camera *camera)
{
	vector_destructor(&(camera->raydirs));
}

void	camera_rotate(t_camera *camera)
{
	calc_raydirs(camera);
}

void	camera_on_resize(t_camera *camera, t_uint32 width, t_uint32 height)
{
	camera->width = width;
	camera->height = height;
	calc_raydirs(camera);
}