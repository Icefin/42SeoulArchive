/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:36:42 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/08 12:40:20 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "gmathlib.h"

t_vec3	make_vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_rgb	make_rgb(double r, double g, double b)
{
	t_rgb	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}


void	clamp_vec3(t_vec3 *out, double min, double max)
{
	if (out->x < min)
		out->x = min;
	if (out->y < min)
		out->y = min;
	if (out->z < min)
		out->z = min;
	
	if (out->x > max)
		out->x = max;
	if (out->y > max)
		out->y = max;
	if (out->z > max)
		out->z = max;
}

void	normalize_vec3(t_vec3 *out)
{
	double mag;

	mag = sqrt(dot_vec3(out, out));
	out->x = out->x / mag;
	out->y = out->y / mag;
	out->z = out->z / mag;
}
