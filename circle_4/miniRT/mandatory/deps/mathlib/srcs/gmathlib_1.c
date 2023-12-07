/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:36:36 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 22:49:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

t_vec2	make_vec2(double x, double y)
{
	t_vec2	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vec2	make_uv(double u, double v)
{
	t_vec2	res;

	res.u = u;
	res.v = v;
	return (res);
}

void	clamp_vec2(t_vec2 *out, double min, double max)
{
	if (out->x < min)
		out->x = min;
	if (out->y < min)
		out->y = min;

	if (out->x > max)
		out->x = max;
	if (out->y > max)
		out->y = max;
}

double	dot_vec2(const t_vec2 *v1, const t_vec2 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y);
}
