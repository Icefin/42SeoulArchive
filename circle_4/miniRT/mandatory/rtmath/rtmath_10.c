/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:09:46 by geshin            #+#    #+#             */
/*   Updated: 2024/01/10 14:20:56 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtmath.h"

static void	calculate_determinant_2(const t_mat4 *m, t_mat3 *t, int r, int c)
{
	int	u;
	int	v;
	int	i;
	int	j;

	u = 0;
	i = -1;
	while (++i < 4)
	{
		if (i != r)
		{
			v = 0;
			j = -1;
			while (++j < 4)
			{
				if (j != c)
				{
					t->elem[u][v] = m->elem[i][j];
					++v;
				}
			}
			++u;
		}
	}
}

static double	calculate_determinant(const t_mat4 *m, int r, int c)
{
	t_mat3	t;
	double	res;

	t = zero_mat3();
	res = 0;
	calculate_determinant_2(m, &t, r, c);
	res = t.elem[0][0] * (t.elem[1][1] * t.elem[2][2] - \
						t.elem[1][2] * t.elem[2][1])
		- t.elem[0][1] * (t.elem[1][0] * t.elem[2][2] - \
						t.elem[1][2] * t.elem[2][0])
		+ t.elem[0][2] * (t.elem[1][0] * t.elem[2][1] - \
						t.elem[1][1] * t.elem[2][0]);
	return (res);
}

static double	inv_mat4_calc_det(t_mat4 *m)
{
	double	det;
	int		c;
	int		sign;

	det = 0;
	c = 0;
	while (c < 4)
	{
		if (c % 2 == 0)
			sign = 1;
		else
			sign = -1;
		det += sign * m->elem[0][c] * calculate_determinant(m, 0, c);
		++c;
	}
	return (det);
}

static void	inv_mat4_calc_idet(t_mat4 *m, t_mat4 *res, double idet)
{
	int	r;
	int	c;
	int	sign;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if ((r + c) % 2 == 0)
				sign = 1;
			else
				sign = -1;
			res->elem[r][c] = sign * idet * calculate_determinant(m, c, r);
			++c;
		}
		++r;
	}
}

t_mat4	inv_mat4(t_mat4 m)
{
	t_mat4	res;
	int		sign;
	double	det;
	double	idet;

	det = inv_mat4_calc_det(&m);
	inv_mat4_calc_idet(&m, &res, 1 / det);
	return (res);
}
