/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:02:12 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/14 17:54:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "commontype.h"
# include "rtmath.h"
# include "vector.h"

# define WINDOW_WIDTH		1024
# define WINDOW_HEIGHT		600
# define MOVE_SPEED			1
# define MOUSE_SENSITIVE	0.002


static const t_vec3 updir = {0.0, 1.0, 0.0};

typedef struct s_camera
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

	float		aspect;
	t_vector	raydirs;
	
	t_bool		is_movable;
	int			k;
}	t_camera;

void	camera_constructor(t_camera *camera, t_vec3 pos, t_vec3 dir, double fov);
void	camera_destructor(t_camera* camera);

void	camera_rotate(t_camera *camera, int x, int y);
void	camera_translate(t_camera *camera, int key);

void	camera_mode_change(t_camera *camera, int key);

void	calc_raydirs(t_camera *camera);

#endif