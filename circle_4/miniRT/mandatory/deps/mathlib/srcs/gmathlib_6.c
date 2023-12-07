/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:37:07 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 22:59:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

t_mat3	identity_mat3(void)
{
	t_mat3	res;
	int		r;
	int		c;

	r = -1;
	while (++r < 3)
	{
		c = -1;
		while (++c < 3)
		{
			res.elem[r][c] = 0.0;
			if (r == c)
				res.elem[r][c] = 1.0;
		}
	}
	return (res);
}

t_mat3	inv_mat3(const t_mat3 *m)
{
	t_mat3	res;
	//__noop;
	return (res);
}

t_mat3	mul_mat3_to_mat3(const t_mat3 *m1, const t_mat3 *m2)
{
	t_mat3	res;
	//__noop;
	return (res);
}

t_vec3	mul_mat3_to_vec3(const t_mat3 *m, const t_vec3 *v)
{
	t_vec3	res;
	//__noop;
	return (res);
}