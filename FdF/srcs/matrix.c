/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:29:08 by geshin            #+#    #+#             */
/*   Updated: 2023/06/17 16:21:35 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

void	init_identity_mat4(double (*m)[4][4])
{
	int	rptr;
	int	cptr;

	rptr = -1;
	while (++rptr < 4)
	{
		cptr = -1;
		while (++cptr < 4)
		{
			if (rptr == cptr)
				(*m)[rptr][cptr] = 1;
			else
				(*m)[rptr][cptr] = 0;
		}
	}
}

void	copy_mat4(double (*dst)[4][4], const double (*src)[4][4])
{
	int rptr;
	int cptr;

	rptr = -1;
	while (++rptr < 4)
	{
		cptr = -1;
		while (++cptr < 4)
			(*dst)[rptr][cptr] = (*src)[rptr][cptr];
	}
}

void	multiply_mat4_to_mat4(double (*m1)[4][4], double (*m2)[4][4], double (*dst)[4][4])
{
	double	temp[4][4];
	int		rptr;
	int		cptr;
	int		ptr;
	
	init_identity_mat4(&temp);
	rptr = -1;
	while (++rptr < 4)
	{
		cptr = -1;
		while (++cptr < 4)
		{
			ptr = -1;
			while (++ptr < 4)
				temp[rptr][cptr] += (*m1)[rptr][ptr] * (*m2)[ptr][cptr];
			if (rptr == cptr)
				temp[rptr][cptr]--;
		}
	}
	copy_mat4(dst, &temp);
}

t_vec4	multiply_mat4_to_vec4(const double (*m)[4][4], t_vec4 v)
{
	t_vec4	res;

	res.x = (*m)[0][0] * v.x + (*m)[0][1] * v.y + (*m)[0][2] * v.z + (*m)[0][3] * v.w;
	res.y = (*m)[1][0] * v.x + (*m)[1][1] * v.y + (*m)[1][2] * v.z + (*m)[1][3] * v.w;
	res.z = (*m)[2][0] * v.x + (*m)[2][1] * v.y + (*m)[2][2] * v.z + (*m)[2][3] * v.w;
	res.w = (*m)[3][0] * v.x + (*m)[3][1] * v.y + (*m)[3][2] * v.z + (*m)[3][3] * v.w;
	return (res);
}