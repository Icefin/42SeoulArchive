/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:10 by singeonho         #+#    #+#             */
/*   Updated: 2023/09/10 14:29:09 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VSHADER_H
# define VSHADER_H

# include "vector.h"
# include "matrix.h"
# include "camera.h"

typedef struct s_vshader
{
	t_mat4	vmatrix;
	t_mat4	pmatrix;
	t_mat4	vpmatrix;
}	t_vshader;

void	init_vertex_shader(t_vshader *shader, t_camera *camera);
void	update_view_matrix(t_vshader *shader, t_camera *camera);
void	update_projection_matrix(t_vshader *shader, t_camera *camera);
void	update_viewport_matrix(t_vshader *shader, t_mat4 *m);
void	vertex_transform(t_vshader *shader, t_vec4 ivert, t_vec3 *overt);

#endif