/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:42:15 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:17:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "commontype.h"
# include "gmathlib.h"
# include "vector.h"
# include "transform.h"

static const t_vec3 updir = {0.0, 1.0, 0.0};

typedef struct t_camera
{
	t_transform	transform;

	double		fov;
	double		near;
	double		far;

	t_mat4		view;
	t_mat4		iview;

	t_uint32	width;
	t_uint32	height;
	t_vector	raydirs;
}	t_camera;

void	initialize_camera(t_camera *camera);
void	destroy_camera(t_camera *camera);

void	camera_on_update(t_camera *camera);
void	camera_on_resize(t_camera *camera, t_uint32 width, t_uint32 height);
//RT
/*
Calculate all the rays on camera
*/
void	calc_raydirs(t_camera *camera);
/*
Returns a ray going from camera through a screen point.
*/
void	screen_point_to_ray();
/*
Transforms position from screen space into viewport space.
*/
void	screen_to_viewport_point();
/*
Transforms a point from screen space into world space,
where world space is defined as the coordinate system
at the very top of your game's hierarchy.
*/
void	screen_to_world_point();

#endif