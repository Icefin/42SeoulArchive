/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/09 02:13:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vshader.h"

void	init_vertex_shader(t_vshader* vshader, t_camera* camera)
{
	double	vpmatrix[4][4];

	init_identity_mat4(&(vpmatrix));
	vpmatrix[0][0] = 1920 / 2;
	vpmatrix[0][3] = 1920 / 2;
	vpmatrix[1][1] = -1080 / 2;
	vpmatrix[1][3] = 1080 / 2;
	vpmatrix[2][2] = 0.5;
	vpmatrix[2][3] = 0.5;

	update_view_matrix(vshader, camera);
	update_projection_matrix(vshader, camera);
	update_viewport_matrix(vshader, &vpmatrix);
}

//void	update_model_matrix(t_vshader* vshader, const double (*m)[4][4])
//{
	//__noop;
//}

void	update_view_matrix(t_vshader* vshader, t_camera* camera)
{
	double	rmatrix[4][4];
	double	tmatrix[4][4];

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

void	update_projection_matrix(t_vshader* vshader, t_camera* camera)
{
	double pmatrix[4][4];

	init_zero_mat4(&(pmatrix));
	if (camera->camera_mode == orthographic)
	{
		pmatrix[0][0] = 2.0 / (camera->right - camera->left);
		pmatrix[0][3] = -(camera->right + camera->left) / (camera->right - camera->left);
		pmatrix[1][1] = 2.0 / (camera->top - camera->bottom);
		pmatrix[1][3] = -(camera->top + camera->bottom) / (camera->top - camera->bottom);
		pmatrix[2][2] = 2.0 / (camera->far - camera->near);
		pmatrix[2][3] = (camera->far + camera->near) / (camera->far - camera->near);
		pmatrix[3][3] = 1.0;
	}
	else if (camera->camera_mode == perspective)
	{
		pmatrix[0][0] = 1.0 / (tan(camera->fov / 2.0) * camera->aspect);
		pmatrix[1][1] = 1.0 / tan(camera->fov / 2.0);
		pmatrix[2][2] = -(camera->far + camera->near) / (camera->far - camera->near);
		pmatrix[2][3] = -(2.0 * camera->far * camera->near) / (camera->far - camera->near);
		pmatrix[3][2] = -1.0;
	}
	copy_mat4(&(vshader->pmatrix), &(pmatrix));
}

void	update_viewport_matrix(t_vshader* vshader, const double (*m)[4][4])
{
	copy_mat4(&(vshader->vpmatrix), m);
}

//static void	model_transform(t_vshader* vshader, t_vec4 in_vert, t_vec4* out_vert)
//{
	//__noop;
//}

static void	view_transform(t_vshader* vshader, t_vec4 in_vert, t_vec4* out_vert)
{
	*out_vert = multiply_mat4_to_vec4(&(vshader->vmatrix), in_vert);
}

static void	projection_transform(t_vshader* vshader, t_vec4 in_vert, t_vec4* out_vert)
{
	*out_vert = multiply_mat4_to_vec4(&(vshader->pmatrix), in_vert);
}

static void	viewport_transform(t_vshader* vshader, t_vec4 in_vert, t_vec4* out_vert)
{
	*out_vert = multiply_mat4_to_vec4(&(vshader->vpmatrix), in_vert);
}

void	vertex_transform(t_vshader* vshader, t_vec4 in_vert, t_vec3* out_vert)
{
	t_vec4	temp1;
	t_vec4	temp2;
	
	view_transform(vshader, in_vert, &temp1);
	projection_transform(vshader, temp1, &temp2);
	viewport_transform(vshader, temp2, &temp1);
	*out_vert = make_vec3(temp1.x / temp1.w, temp1.y / temp1.w, temp1.z / temp1.w);
}
