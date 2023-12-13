/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:42:15 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 18:59:02 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "commontype.h"
# include "gmathlib.h"
# include "vector.h"

static const t_vec3 updir = {0.0, 1.0, 0.0};

typedef struct t_camera
{
	t_vec3		position;
	t_vec3		forward;

	double		fov;
	double		near;
	double		far;

	t_mat4		view;
	t_mat4		iview;

	t_mat4		proj;
	t_mat4		iproj;

	t_uint32	width;
	t_uint32	height;
	float		aspect;
	t_vector	raydirs;
}	t_camera;

void	initialize_camera(t_camera *camera, const t_vec3 *pos, const t_vec3 *dir, const double fov);
void	destroy_camera(t_camera *camera);

void	camera_on_update(t_camera *camera);
void	camera_on_resize(t_camera *camera, t_uint32 width, t_uint32 height);
void	calc_raydirs(t_camera *camera);

#endif