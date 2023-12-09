/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:36:56 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/08 12:41:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

t_vec4	make_vec4(double x, double y, double z, double w)
{
	t_vec4	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

t_rgba	make_rgba(double r, double g, double b, double a)
{
	t_rgba	res;

	res.r = r;
	res.g = g;
	res.b = b;
	res.a = a;
	return (res);
}

t_vec4	vec3_to_vec4(const t_vec3 *v, double w)
{
	t_vec4	res;

	res.x = v->x;
	res.y = v->y;
	res.z = v->z;
	res.w = w;
	return (res);
}

t_vec3	vec4_to_vec3(const t_vec4 *v)
{
	t_vec3	res;

	res.x = v->x;
	res.y = v->y;
	res.z = v->z;
	return (res);
}

void	clamp_vec4(t_vec4 *out, double min, double max)
{
	if (out->x < min)
		out->x = min;
	if (out->y < min)
		out->y = min;
	if (out->z < min)
		out->z = min;
	if (out->w < min)
		out->w = min;

	if (out->x > max)
		out->x = max;
	if (out->y > max)
		out->y = max;
	if (out->z > max)
		out->z = max;
	if (out->w > max)
		out->w = max;
}
