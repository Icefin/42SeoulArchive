/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:37 by geshin            #+#    #+#             */
/*   Updated: 2023/12/31 01:05:51 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_mat3	zero_mat3()
{
	t_mat3	res;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			res.elem[r][c] = 0;
		}
	}
	return (res);
}

t_mat3	identity_mat3()
{
	t_mat3	res;

	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			res.elem[r][c] = 0;
			if (r == c)
				res.elem[r][c] = 1;
		}
	}
	return (res);
}

t_mat3	inv_mat3(t_mat3 m)
{
	t_mat3	res;
	double	det;
	double	idet;
	
	det = m.elem[0][0] * (m.elem[1][1] * m.elem[2][2] - m.elem[1][2] * m.elem[2][1])
		- m.elem[0][1] * (m.elem[1][0] * m.elem[2][2] - m.elem[1][2] * m.elem[2][0])
		+ m.elem[0][2] * (m.elem[1][0] * m.elem[2][1] - m.elem[1][1] * m.elem[2][0]);

	idet = 1 / det;
	res.elem[0][0] = idet * (m.elem[1][1] * m.elem[2][2] - m.elem[1][2] * m.elem[2][1]);
	res.elem[0][1] = -idet * (m.elem[0][1] * m.elem[2][2] - m.elem[0][2] * m.elem[2][1]);
	res.elem[0][2] = idet * (m.elem[0][1] * m.elem[1][2] - m.elem[0][2] * m.elem[1][1]);

	res.elem[1][0] = -idet * (m.elem[1][0] * m.elem[2][2] - m.elem[1][2] * m.elem[2][0]);
	res.elem[1][1] = idet * (m.elem[0][0] * m.elem[2][2] - m.elem[0][2] * m.elem[2][0]);
	res.elem[1][2] = -idet * (m.elem[0][0] * m.elem[1][2] - m.elem[0][2] * m.elem[1][0]);

	res.elem[2][0] = idet * (m.elem[1][0] * m.elem[2][1] - m.elem[1][1] * m.elem[2][0]);
	res.elem[2][1] = -idet * (m.elem[0][0] * m.elem[2][1] - m.elem[0][1] * m.elem[2][0]);
	res.elem[2][2] = idet * (m.elem[0][0] * m.elem[1][1] - m.elem[0][1] * m.elem[1][0]);
	return (res);
}

t_mat3	mul_mat3_to_mat3(t_mat3 m1, t_mat3 m2)
{
	t_mat3	res;

	res = identity_mat3();
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			for (int i = 0; i < 3; ++i)
				res.elem[r][c] += m1.elem[r][i] * m2.elem[i][c];
			if (r == c)
				res.elem[r][c] -= 1;
		}
	}
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