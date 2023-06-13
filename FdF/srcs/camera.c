/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:31:25 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 12:13:47 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "math.h"

#include <stdio.h>

void	test_camera_state_print(t_camera* camera) {
	printf("\n");
	printf("Camera Position : %f, %f, %f\n", camera->position.x, camera->position.y, camera->position.z);
	printf("Camera Gaze     : %f, %f, %f\n\n", camera->gaze.x, camera->gaze.y, camera->gaze.z);
}

void	init_camera(t_camera* camera)
{
	camera->position.x = CAMERA_INIT_X; 
	camera->position.y = CAMERA_INIT_Y;
	camera->position.z = CAMERA_INIT_Z;
	camera->gaze.x = CAMERA_INIT_G_X;
	camera->gaze.y = CAMERA_INIT_G_Y;
	camera->gaze.z = CAMERA_INIT_G_Z;
}

void	translate_camera(t_camera* camera, t_vec3 pos)
{
	camera->position.x += pos.x;
	camera->position.y += pos.y;
	camera->position.z += pos.z;
}

void	rotate_camera(t_camera* camera, t_vec3 ang)
{
	camera->gaze.x = camera->gaze.x * (cos(ang.y) * cos(ang.z)) \
						- camera->gaze.y * (cos(ang.y) * sin(ang.z)) \
						+ camera->gaze.z * sin(ang.y);

	camera->gaze.y = camera->gaze.x * (cos(ang.x) * sin(ang.z) + sin(ang.x) * sin(ang.y) * cos(ang.z)) \
						+ camera->gaze.y * (cos(ang.x) * cos(ang.z) - sin(ang.x) * sin(ang.y) * sin(ang.z)) \
						- camera->gaze.z * (sin(ang.x) * cos(ang.y));

	camera->gaze.z = camera->gaze.x * (sin(ang.x) * sin(ang.z) - cos(ang.x) * sin(ang.y) * cos(ang.z)) \
						+ camera->gaze.y * (sin(ang.x) * cos(ang.z) + cos(ang.x) * sin(ang.y) * sin(ang.z)) \
						+ camera->gaze.z * (cos(ang.x) * cos(ang.y));
}