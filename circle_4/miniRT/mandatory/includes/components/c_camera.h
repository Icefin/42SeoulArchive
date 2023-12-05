/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:58:22 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/05 23:11:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "gmathlib.h"

typedef enum s_projection_type
{
	ORTHOGRAPHIC,
	PERSPECTIVE
}	t_projection_type;

typedef struct s_c_camera
{
	t_projection_type	type;

	double				fov;
	double				near;
	double				far;
}	t_c_camera;

void	zoom_camera();
//RT
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