/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:37 by geshin            #+#    #+#             */
/*   Updated: 2024/01/10 14:02:26 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_mat3	zero_mat3(void)
{
	t_mat3	res;
	int		r;
	int		c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 0)
		{
			res.elem[r][c] = 0;
			++c;
		}
		++r;
	}
	return (res);
}

t_mat3	identity_mat3(void)
{
	t_mat3	res;
	int		r;
	int		c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 3)
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

static void	inv_mat3_2(t_mat3 *res, t_mat3 *m, double det)
{
	double	idet;

	idet = 1 / det;
	res->elem[0][0] = idet * (m->elem[1][1] * m->elem[2][2] - \
							m->elem[1][2] * m->elem[2][1]);
	res->elem[0][1] = -idet * (m->elem[0][1] * m->elem[2][2] - \
							m->elem[0][2] * m->elem[2][1]);
	res->elem[0][2] = idet * (m->elem[0][1] * m->elem[1][2] - \
							m->elem[0][2] * m->elem[1][1]);
	res->elem[1][0] = -idet * (m->elem[1][0] * m->elem[2][2] - \
							m->elem[1][2] * m->elem[2][0]);
	res->elem[1][1] = idet * (m->elem[0][0] * m->elem[2][2] - \
							m->elem[0][2] * m->elem[2][0]);
	res->elem[1][2] = -idet * (m->elem[0][0] * m->elem[1][2] - \
							m->elem[0][2] * m->elem[1][0]);
	res->elem[2][0] = idet * (m->elem[1][0] * m->elem[2][1] - \
						m->elem[1][1] * m->elem[2][0]);
	res->elem[2][1] = -idet * (m->elem[0][0] * m->elem[2][1] - \
						m->elem[0][1] * m->elem[2][0]);
	res->elem[2][2] = idet * (m->elem[0][0] * m->elem[1][1] - \
						m->elem[0][1] * m->elem[1][0]);
}

t_mat3	inv_mat3(t_mat3 m)
{
	t_mat3	res;
	double	det;

	det = m.elem[0][0] * (m.elem[1][1] * m.elem[2][2] - \
						m.elem[1][2] * m.elem[2][1])
		- m.elem[0][1] * (m.elem[1][0] * m.elem[2][2] - \
						m.elem[1][2] * m.elem[2][0])
		+ m.elem[0][2] * (m.elem[1][0] * m.elem[2][1] - \
						m.elem[1][1] * m.elem[2][0]);
	inv_mat3_2(&res, &m, det);
	return (res);
}

t_mat3	mul_mat3_to_mat3(t_mat3 m1, t_mat3 m2)
{
	t_mat3	res;
	int		r;
	int		c;
	int		i;

	res = identity_mat3();
	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 3)
		{
			i = 0;
			while (i < 3)
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
