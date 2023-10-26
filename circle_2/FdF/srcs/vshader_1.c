/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/10/26 16:51:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vshader.h"

void	init_vertex_shader(t_vshader *vshader, t_camera *camera)
{
	double	vpmatrix[4][4];

	init_identity_mat4(&(vpmatrix));
	vpmatrix[0][0] = 1024 / 2;
	vpmatrix[0][3] = 1024 / 2;
	vpmatrix[1][1] = -768 / 2;
	vpmatrix[1][3] = 768 / 2;
	vpmatrix[2][2] = 0.5;
	vpmatrix[2][3] = 0.5;
	
	update_view_matrix(vshader, camera);
	update_projection_matrix(vshader, camera);
	update_viewport_matrix(vshader, &vpmatrix);
}

void	update_view_matrix(t_vshader *vshader, t_camera *camera)
{
	t_mat4	rmatrix;
	t_mat4	tmatrix;

	init_identity_mat4(&(rmatrix));
	rmatrix[0][0] = camera->basis_u.x;
	rmatrix[0][1] = camera->basis_u.y;
	rmatrix[0][2] = camera->basis_u.z;
	rmatrix[1][0] = camera->basis_v.x;
	rmatrix[1][1] = camera->basis_v.y;
	rmatrix[1][2] = camera->basis_v.z;
	rmatrix[2][0] = camera->basis_n.x;
	rmatrix[2][1] = camera->basis_n.y;
	rmatrix[2][2] = camera->basis_n.z;

	init_identity_mat4(&(tmatrix));
	tmatrix[0][3] = -(camera->position.x);
	tmatrix[1][3] = -(camera->position.y);
	tmatrix[2][3] = -(camera->position.z);

	multiply_mat4_to_mat4(&(rmatrix), &(tmatrix), &(vshader->vmatrix));
}

void	update_projection_matrix(t_vshader *vshader, t_camera *camera)
{
	t_mat4	pm;

	init_zero_mat4(&(pm));
	if (camera->camera_mode == ORTHOGRAPHIC)
	{
		pm[0][0] = 40.0 / (camera->right - camera->left);
		pm[0][3] = -(camera->right + camera->left)
			/ (camera->right - camera->left);
		pm[1][1] = 40.0 / (camera->top - camera->bottom);
		pm[1][3] = -(camera->top + camera->bottom)
			/ (camera->top - camera->bottom);
		pm[2][2] = 40.0 / (camera->far - camera->near);
		pm[2][3] = (camera->far + camera->near) / (camera->far - camera->near);
		pm[3][3] = 1.0;
	}
	else if (camera->camera_mode == PERSPECTIVE)
	{
		pm[0][0] = 1.0 / (tan(camera->fov / 2.0) * camera->aspect);
		pm[1][1] = 1.0 / tan(camera->fov / 2.0);
		pm[2][2] = -(camera->far + camera->near) / (camera->far - camera->near);
		pm[2][3] = -(2.0 * camera->far * camera->near)
			/ (camera->far - camera->near);
		pm[3][2] = -1.0;
	}
	copy_mat4(&(vshader->pmatrix), &(pm));
}

void	update_viewport_matrix(t_vshader *vshader, t_mat4 *m)
{
	copy_mat4(&(vshader->vpmatrix), m);
}
