/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/06/17 12:41:29 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "vector.h"
#include "math.h"

#define MOVE_OFFSET 10.0
#define ROT_OFFSET M_PI / 24

typedef struct s_camera
{
	t_vec4	position;
	//camera space basis
	double	basis[4][4];
	//view transformation
	double	vmatrix[4][4];
	//projection
	double	pmatrix[4][4];
	//view -> projection
	double	pvmatrix[4][4];
	double 	fov;
	double 	near;
	double 	far;
}	t_camera;

void	init_camera(t_camera* camera);
void	translate_camera(t_camera* camera, int keycode);
void	rotate_camera(t_camera* camera, int keycode);
void	update_vmatrix(t_camera* camera);
void	update_pmatrix(t_camera* camera);
void	update_pvmatrix(t_camera* camera);

#endif