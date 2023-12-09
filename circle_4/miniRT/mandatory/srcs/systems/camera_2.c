/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:07:08 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/09 21:28:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "commontype.h"

void	calc_raydirs(t_camera *camera)
{
	t_vec4	uv;
	t_vec4	target;
	t_vec3	raydir;

	vector_resize(&(camera->raydirs), camera->width * camera->height);
	for (t_uint32 y = 0; y < camera->height; ++y) {
		for (t_uint32 x = 0; x < camera->width; ++x) {
			uv = make_vec4(2.0 * (float)x / (float)(camera->width) - 1.0,
							2.0 * (float)y / (float)camera->height - 1.0, 1.0, 1.0);
			target = mul_mat4_to_vec4(&(camera->iproj), &uv);
			raydir; //glm::vec3(ivew * glm::vec4(glm::normalize(glm::vec3(target) / target.w), 0));
			vector_set_idx(&(camera->raydirs), x + y * camera->width, &(raydir));
		}
	}
}