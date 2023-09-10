/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vshader_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:49:57 by geshin            #+#    #+#             */
/*   Updated: 2023/09/10 14:54:56 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vshader.h"

static void	view_transform(t_vshader *vshader, t_vec4 iv, t_vec4 *ov)
{
	*ov = multiply_mat4_to_vec4(&(vshader->vmatrix), iv);
}

static void	projection_transform(t_vshader *vshader, t_vec4 iv, t_vec4 *ov)
{
	*ov = multiply_mat4_to_vec4(&(vshader->pmatrix), iv);
}

static void	viewport_transform(t_vshader *vshader, t_vec4 iv, t_vec4 *ov)
{
	*ov = multiply_mat4_to_vec4(&(vshader->vpmatrix), iv);
}

void	vertex_transform(t_vshader *vshader, t_vec4 iv, t_vec3 *ov)
{
	t_vec4	temp;
	t_vec4	stemp;

	view_transform(vshader, iv, &temp);
	projection_transform(vshader, temp, &stemp);
	viewport_transform(vshader, stemp, &temp);
	*ov = make_vec3(temp.x / temp.w, temp.y / temp.w, temp.z / temp.w);
}
