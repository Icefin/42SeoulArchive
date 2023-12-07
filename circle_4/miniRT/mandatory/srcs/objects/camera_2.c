/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:07:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 15:41:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	calc_raydirs(t_camera *camera)
{
	t_uint32	width;
	t_uint32	height;
	t_vec2		uv;
	t_vec4		target;

	vector_destructor(&(c_camera->raydirs));
	vector_constructor(&(c_camera->raydirs), width * height, sizeof(t_vec3));
	for (t_uint32 y = 0; y < height; ++y) {
		for (t_uint32 x = 0; x < width; ++x) {
			uv = make_vec2(2.0 * (float)x / (float)width - 1.0, 2.0 * (float)y / (float)height - 1.0);
			
			target = mul_mat4_to_vec4(c_camera->iview, {uv.x, uv.y, 1, 1});
			t_vec3 raydir = make_vec3();
			vector_insert_index(&(c_camera->raydirs), raydir, x + y * width);
		}
	}
}