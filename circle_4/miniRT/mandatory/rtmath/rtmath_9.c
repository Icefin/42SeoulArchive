/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:38 by geshin            #+#    #+#             */
/*   Updated: 2024/01/08 17:20:08 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_mat4	identity_mat4(void)
{
	t_mat4	res;
	int		r;
	int		c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			res.elem[r][c] = 0;
			if (r == c)
				res.elem[r][c] = 1;
			++c;
		}
		++r;
	}
	return (res);
}

t_mat4	transpose_mat4(t_mat4 m)
{
	t_mat4	res;
	int		r;
	int		c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			res.elem[r][c] = m.elem[c][r];
			++c;
		}
		++r;
	}
	return (res);
}

t_mat4	mul_mat4_to_mat4(t_mat4 m1, t_mat4 m2)
{
	t_mat4	res;
	int		r;
	int		c;
	int		i;

	res = identity_mat4();
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			i = 0;
			while (i < 4)
			{
				res.elem[r][c] += m1.elem[r][i] * m2.elem[i][c];
				++i;
			}
			if (r == c)
				res.elem[r][c] -= 1;
			++c;
		}
		++r;
	}
	return (res);
}

t_vec4	mul_mat4_to_vec4(t_mat4 m, t_vec4 v)
{
	t_vec4	res;

	res.x = m.elem[0][0] * v.x + m.elem[0][1] * v.y
		+ m.elem[0][2] * v.z + m.elem[0][3] * v.w;
	res.y = m.elem[1][0] * v.x + m.elem[1][1] * v.y
		+ m.elem[1][2] * v.z + m.elem[1][3] * v.w;
	res.z = m.elem[2][0] * v.x + m.elem[2][1] * v.y
		+ m.elem[2][2] * v.z + m.elem[2][3] * v.w;
	res.w = m.elem[3][0] * v.x + m.elem[3][1] * v.y
		+ m.elem[3][2] * v.z + m.elem[3][3] * v.w;
	return (res);
}
