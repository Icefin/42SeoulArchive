/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:29:08 by geshin            #+#    #+#             */
/*   Updated: 2023/09/11 17:13:26 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

void	init_zero_mat4(t_mat4 *m)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			(*m)[r][c] = 0.0;
	}
}

void	init_identity_mat4(t_mat4 *m)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			if (r == c)
				(*m)[r][c] = 1.0;
			else
				(*m)[r][c] = 0.0;
		}
	}
}

void	copy_mat4(t_mat4 *dst, t_mat4 *src)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
			(*dst)[r][c] = (*src)[r][c];
	}
}

void	multiply_mat4_to_mat4(t_mat4 *m1, t_mat4 *m2, t_mat4 *dst)
{
	t_mat4	temp;
	int		r;
	int		c;
	int		i;

	init_zero_mat4(&temp);
	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			while (++i < 4)
				temp[r][c] += (*m1)[r][i] * (*m2)[i][c];
		}
	}
	copy_mat4(dst, &temp);
}

t_vec4	multiply_mat4_to_vec4(t_mat4 *m, t_vec4 v)
{
	t_vec4	res;

	res.x = (*m)[0][0] * v.x + (*m)[0][1] * v.y
		+ (*m)[0][2] * v.z + (*m)[0][3] * v.w;
	res.y = (*m)[1][0] * v.x + (*m)[1][1] * v.y
		+ (*m)[1][2] * v.z + (*m)[1][3] * v.w;
	res.z = (*m)[2][0] * v.x + (*m)[2][1] * v.y
		+ (*m)[2][2] * v.z + (*m)[2][3] * v.w;
	res.w = (*m)[3][0] * v.x + (*m)[3][1] * v.y
		+ (*m)[3][2] * v.z + (*m)[3][3] * v.w;
	return (res);
}
