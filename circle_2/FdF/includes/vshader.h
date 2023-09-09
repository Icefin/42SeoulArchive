/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:10 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/09 16:12:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VSHADER_H
# define VSHADER_H

#include "vector.h"
#include "matrix.h"
#include "camera.h"

typedef struct s_vshader
{
	double vmatrix[4][4];
	double pmatrix[4][4];
	double vpmatrix[4][4];
}	t_vshader;

void	init_vertex_shader(t_vshader* shader, t_camera* camera);
void	update_view_matrix(t_vshader* shader, t_camera* camera);
void	update_projection_matrix(t_vshader* shader, t_camera* camera);
void	update_viewport_matrix(t_vshader* shader, const double (*m)[4][4]);
void	vertex_transform(t_vshader* shader, t_vec4 in_vert, t_vec3* out_vert);

#endif