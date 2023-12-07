/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:07:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:11:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	calc_raydirs(t_camera *camera)
{
	t_vec2		uv;
	t_vec4		target;

	vector_destructor(&(camera->raydirs));
	vector_constructor(&(camera->raydirs), camera->width * camera->height, sizeof(t_vec3));
	for (t_uint32 y = 0; y < camera->height; ++y) {
		for (t_uint32 x = 0; x < camera->width; ++x) {
			uv = make_vec2(2.0 * (float)x / (float)(camera->width) - 1.0,
							 2.0 * (float)y / (float)camera->height - 1.0);
			target = mul_mat4_to_vec4(&(camera->iview), &make_vec4(uv.x, uv.y, 1, 1));
			t_vec3 raydir = make_vec3(target.x / target.w, target.y / target.w, target.z / target.w);
			vector_set_idx(&(camera->raydirs), x + y * camera->width, &(raydir));
		}
	}
}