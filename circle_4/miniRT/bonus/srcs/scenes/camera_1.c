/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:36:14 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/20 16:58:50 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "camera.h"
#include "thread.h"

void	*calc_raydirs_routine(void *attr)
{
	t_child		*child = (t_child *)attr;
	t_camera	*camera = child->camera;
	t_vec4		uv;
	t_vec4		target;
	t_vec3		raydir;

	for (t_uint32 y = child->miny; y < child->maxy; y += camera->k) {
		for (t_uint32 x = 0; x < WINDOW_WIDTH; x += camera->k) {
			uv = make_vec4(2.0 * (float)x / (WINDOW_WIDTH) - 1.0,
							1.0 - 2.0 * (float)y / (WINDOW_HEIGHT), 1.0, 1.0);
			target = mul_mat4_to_vec4(camera->iproj, uv);
			target = vec4_multiply_num(target, 1 / target.w);
			target.w = 0;
			raydir = vec4_to_vec3(mul_mat4_to_vec4(camera->iview, target));
			raydir = normalize_vec3(raydir);
			vector_set_idx(&(camera->raydirs), x + y * WINDOW_WIDTH, &(raydir));
		}
	}
}

//raydir = glm::vec3(iview * glm::vec4(glm::normalize(glm::vec3(target) / target.w), 0));
void	calc_raydirs(t_camera *camera)
{
	t_vec4	uv;
	t_vec4	target;
	t_vec3	raydir;

#define MT 1
#if MT
	t_child	*child = (t_child *)malloc(sizeof(t_child) * THREAD_CNT);

	for (int i = 0; i < THREAD_CNT; ++i)
	{
		child[i].camera = camera;
		child[i].miny = ((float)i / THREAD_CNT) * WINDOW_HEIGHT;
		child[i].maxy = ((float)(i + 1) / THREAD_CNT) * WINDOW_HEIGHT;
		pthread_create(&child[i].thread, 0, (void *)calc_raydirs_routine, (void *)&child[i]);
	}
	for (int i = 0; i < THREAD_CNT; ++i)
		pthread_join(child[i].thread, NULL);
	free(child);
#else
	for (t_uint32 y = 0; y < WINDOW_HEIGHT; y += camera->k) {
		for (t_uint32 x = 0; x < WINDOW_WIDTH; x += camera->k) {
			uv = make_vec4(2.0 * (float)x / (WINDOW_WIDTH) - 1.0,
							1.0 - 2.0 * (float)y / (WINDOW_HEIGHT), 1.0, 1.0);
			target = mul_mat4_to_vec4(camera->iproj, uv);
			target = vec4_multiply_num(target, 1 / target.w);
			target.w = 0;
			raydir = vec4_to_vec3(mul_mat4_to_vec4(camera->iview, target));
			raydir = normalize_vec3(raydir);
			vector_set_idx(&(camera->raydirs), x + y * WINDOW_WIDTH, &(raydir));
		}
	}
#endif
}

void	camera_constructor(t_camera *camera, t_vec3 pos, t_vec3 dir, double fov)
{	
	camera->position = pos;
	camera->forward = dir;
	camera->aspect = (float)WINDOW_WIDTH / WINDOW_HEIGHT;
	camera->fov = fov;
	camera->near = 0.1;
	camera->far = 1000.0;
	camera->view = make_view_mat(camera->position, \
		vec3_plus_vec3(camera->position, camera->forward), \
		updir);
	camera->iview = inv_mat4(camera->view);
	camera->proj = make_proj_mat(camera->fov, \
		camera->aspect, \
		camera->near, \
		camera->far);
	camera->iproj = inv_mat4(camera->proj);
	camera->is_movable = FALSE;
	camera->k = 1;
	vector_n_constructor(&(camera->raydirs), WINDOW_WIDTH * WINDOW_HEIGHT, sizeof(t_vec3));
	calc_raydirs(camera);
}

void	camera_destructor(t_camera* camera)
{
	vector_destructor(&(camera->raydirs));
}