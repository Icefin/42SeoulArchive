/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:37:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:02:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

t_mat4	identity_mat4(void)
{
	t_mat4	res;
	int		r;
	int		c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			res.elem[r][c] = 0.0;
			if (r == c)
				res.elem[r][c] = 1.0;
		}
	}
	return (res);
}

t_mat4	inv_mat4(const t_mat4 *m)
{
	t_mat4	res;
	//__noop;
	return (res);
}

t_mat4	transpose_mat4(const t_mat4 *m)
{
	t_mat4	res;
	//__noop;
	return (res);
}

t_mat4	mul_mat4_to_mat4(const t_mat4 *m1, const t_mat4 *m2)
{
	t_mat4	res;
	//__noop;
	return (res);
}

t_vec4	mul_mat4_to_vec4(const t_mat4 *m, const t_vec4 *v)
{
	t_vec4	res;
	//__noop;
	return (res);
}
