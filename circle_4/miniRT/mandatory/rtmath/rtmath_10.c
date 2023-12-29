/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:09:46 by geshin            #+#    #+#             */
/*   Updated: 2023/12/28 16:40:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "rtmath.h"

static double	calculate_determinant(const t_mat4 *m, int r, int c)
{
	t_mat3	t = zero_mat3();
	double	res = 0;

	int u = 0;
	for (int i = 0; i < 4; ++i) {
		if (i == r)
			continue;
		int v = 0;
		for (int j = 0; j < 4; ++j) {
			if (j == c)
				continue;
			t.elem[u][v] = m->elem[i][j];
			v++;
		}
		u++;
	}

	res = t.elem[0][0] * (t.elem[1][1] * t.elem[2][2] - t.elem[1][2] * t.elem[2][1])
		- t.elem[0][1] * (t.elem[1][0] * t.elem[2][2] - t.elem[1][2] * t.elem[2][0])
		+ t.elem[0][2] * (t.elem[1][0] * t.elem[2][1] - t.elem[1][1] * t.elem[2][0]);
	return (res);
}

t_mat4	inv_mat4(t_mat4 m)
{
	t_mat4	res;
	int		sign;
	double	det;
	double	idet;

	det = 0;
	for (int c = 0; c < 4; ++c) {
		sign = (c % 2 == 0) ? 1 : -1;
		det += sign * m.elem[0][c] * calculate_determinant(&m, 0, c);
	}

	if (det == 0)
		printf("InvMat doesn't exist\n");
	idet = 1 / det;
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			sign = ((r + c) % 2 == 0) ? 1 : -1;
			res.elem[r][c] = sign * idet * calculate_determinant(&m, c, r);
		}
	}
	return (res);
}

#include <stdio.h>
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