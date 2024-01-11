/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:28 by geshin            #+#    #+#             */
/*   Updated: 2024/01/08 17:07:45 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtmath.h"

t_vec3	vec3_multiply_num(t_vec3 v, double num)
{
	t_vec3	res;

	res.x = v.x * num;
	res.y = v.y * num;
	res.z = v.z * num;
	return (res);
}

void	clamp_vec3(t_vec3 *out, double min, double max)
{
	if (out->x < min)
		out->x = min;
	else if (out->x > max)
		out->x = max;
	if (out->y < min)
		out->y = min;
	else if (out->y > max)
		out->y = max;
	if (out->z < min)
		out->z = min;
	else if (out->z > max)
		out->z = max;
}

t_vec3	normalize_vec3(t_vec3 v)
{
	t_vec3	res;
	double	mag;

	mag = sqrt(dot_vec3(v, v));
	res.x = v.x / mag;
	res.y = v.y / mag;
	res.z = v.z / mag;
	return (res);
}

double	dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double	res;

	res = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (res);
}

t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.y * v2.z - v1.z * v2.y);
	res.y = (v1.z * v2.x - v1.x * v2.z);
	res.z = (v1.x * v2.y - v1.y * v2.x);
	return (res);
}
