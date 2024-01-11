/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:06:14 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 13:57:05 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"
#include <math.h>

t_quat	make_quat(double w, double x, double y, double z)
{
	t_quat	res;

	res.w = w;
	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_quat	normalize_quat(t_quat q)
{
	t_quat	res;
	double	mag;

	mag = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	res.w = q.w / mag;
	res.x = q.x / mag;
	res.y = q.y / mag;
	res.z = q.z / mag;
	return (res);
}

t_quat	angle_axis(double angle, t_vec3 axis)
{
	t_quat	res;
	double	s;

	s = sin(angle / 2);
	res.w = cos(angle / 2);
	res.x = axis.x * s;
	res.y = axis.y * s;
	res.z = axis.z * s;
	return (res);
}

t_quat	cross_quat(t_quat q1, t_quat q2)
{
	t_quat	res;
	t_vec3	u;
	t_vec3	v;
	t_vec3	vec;

	u = make_vec3(q1.x, q1.y, q1.z);
	v = make_vec3(q2.x, q2.y, q2.z);
	res.w = q1.w * q2.w - dot_vec3(u, v);
	vec = cross_vec3(u, v);
	vec = vec3_plus_vec3(vec, vec3_multiply_num(v, q1.w));
	vec = vec3_plus_vec3(vec, vec3_multiply_num(u, q2.w));
	res.x = vec.x;
	res.y = vec.y;
	res.z = vec.z;
	return (res);
}

t_quat	hamilton_product(t_quat q1, t_quat q2)
{
	t_quat	res;

	res.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	res.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	res.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	res.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (res);
}
