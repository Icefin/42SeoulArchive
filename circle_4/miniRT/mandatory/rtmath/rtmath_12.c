/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:56:27 by jihwjeon          #+#    #+#             */
/*   Updated: 2024/01/10 14:21:03 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtmath.h"

extern t_quat	hamilton_product(t_quat q1, t_quat q2);

t_vec3	rotate_vec3(t_quat q, t_vec3 v)
{
	t_vec3	res;
	t_quat	rq;
	t_quat	vq;
	t_quat	cq;

	vq = make_quat(0, v.x, v.y, v.z);
	cq = make_quat(q.w, -q.x, -q.y, -q.z);
	rq = hamilton_product(hamilton_product(q, vq), cq);
	res = make_vec3(rq.x, rq.y, rq.z);
	return (res);
}

t_vec3	mul_mat3_to_vec3(t_mat3 m, t_vec3 v)
{
	t_vec3	res;

	res.x = m.elem[0][0] * v.x + m.elem[0][1] * v.y + m.elem[0][2] * v.z;
	res.y = m.elem[1][0] * v.x + m.elem[1][1] * v.y + m.elem[1][2] * v.z;
	res.z = m.elem[2][0] * v.x + m.elem[2][1] * v.y + m.elem[2][2] * v.z;
	return (res);
}

//glm::lookAt();
t_mat4	make_view_mat(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_mat4	view;
	t_vec3	zdir;
	t_vec3	xdir;
	t_vec3	ydir;

	zdir = normalize_vec3(vec3_minus_vec3(pos, target));
	xdir = normalize_vec3(cross_vec3(up, zdir));
	ydir = normalize_vec3(cross_vec3(zdir, xdir));
	view.elem[0][0] = xdir.x;
	view.elem[0][1] = xdir.y;
	view.elem[0][2] = xdir.z;
	view.elem[0][3] = -dot_vec3(xdir, pos);
	view.elem[1][0] = ydir.x;
	view.elem[1][1] = ydir.y;
	view.elem[1][2] = ydir.z;
	view.elem[1][3] = -dot_vec3(ydir, pos);
	view.elem[2][0] = zdir.x;
	view.elem[2][1] = zdir.y;
	view.elem[2][2] = zdir.z;
	view.elem[2][3] = -dot_vec3(zdir, pos);
	view.elem[3][0] = 0;
	view.elem[3][1] = 0;
	view.elem[3][2] = 0;
	view.elem[3][3] = 1.0;
	return (view);
}

//glm::perspective();
t_mat4	make_proj_mat(float fov, float aspect, float near, float far)
{
	t_mat4	proj;

	proj.elem[0][0] = 1.0 / (aspect * tan(fov / 2));
	proj.elem[1][0] = 0.0;
	proj.elem[2][0] = 0.0;
	proj.elem[3][0] = 0.0;
	proj.elem[0][1] = 0.0;
	proj.elem[1][1] = 1 / (tan(fov / 2));
	proj.elem[2][1] = 0.0;
	proj.elem[3][1] = 0.0;
	proj.elem[0][2] = 0.0;
	proj.elem[1][2] = 0.0;
	proj.elem[2][2] = -(far + near) / (far - near);
	proj.elem[3][2] = -1.0;
	proj.elem[0][3] = 0.0;
	proj.elem[1][3] = 0.0;
	proj.elem[2][3] = -(2 * far * near) / (far - near);
	proj.elem[3][3] = 0.0;
	return (proj);
}
