/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:35 by geshin            #+#    #+#             */
/*   Updated: 2023/12/20 14:29:35 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

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

t_vec4	vec4_plus_vec4(t_vec4 v1, t_vec4 v2)
{
	t_vec4	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	res.w = v1.w + v2.w;
	return (res);
}

t_vec4	vec4_minus_vec4(t_vec4 v1, t_vec4 v2)
{
	t_vec4	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	res.w = v1.w - v2.w;
	return (res);
}

t_vec4	vec4_multiply_vec4(t_vec4 v1, t_vec4 v2)
{
	t_vec4	res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	res.w = v1.w * v2.w;
	return (res);
}