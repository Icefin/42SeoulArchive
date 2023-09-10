/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:00:54 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 15:16:39 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "math.h"

# define INIT_YAW 3.926990816987241394997454335680
# define INIT_PITCH -0.615472907

# define M_PI_3 1.047197551196597631317786181171
# define M_PI_6 0.523598775598298815658893090585
# define M_PI_36 0.087266462599716473902411451036
# define M_PI_72 0.043633231299858236951205725518

typedef enum e_projection_type
{
	ORTHOGRAPHIC = 0,
	PERSPECTIVE
}	t_projection_type;

typedef struct s_camera
{
	t_vec3				position;
	t_vec3				basis_u;
	t_vec3				basis_v;
	t_vec3				basis_n;
	t_vec3				worldup;
	double				yaw;
	double				pitch;
	double				near;
	double				far;
	double				left;
	double				right;
	double				bottom;
	double				top;
	double				aspect;
	double				fov;
	t_projection_type	camera_mode;
}	t_camera;

void	init_camera(t_camera *camera);
void	switch_camera_mode(t_camera *camera);
void	translate_camera(t_camera *camera, int keycode);
void	rotate_camera(t_camera *camera, int keycode);
void	zoom_camera(t_camera *camera, int keycode);

#endif