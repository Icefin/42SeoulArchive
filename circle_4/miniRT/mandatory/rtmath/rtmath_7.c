/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:36 by geshin            #+#    #+#             */
/*   Updated: 2023/12/20 14:30:09 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_vec4	vec4_multiply_num(t_vec4 v, double num)
{
	t_vec4	res;

	res.x = v.x * num;
	res.y = v.y * num;
	res.z = v.z * num;
	res.w = v.w * num;
	return (res);
}

void	clamp_vec4(t_vec4 *out, double min, double max)
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
	if (out->w < min)
		out->w = min;
	else if (out->w > max)
		out->w = max;
}

t_vec4	vec3_to_vec4(t_vec3 v, double w)
{
	t_vec4	res;

	res.x = v.x;
	res.y = v.y;
	res.z = v.z;
	res.w = w;
	return (res);
}

t_vec3	vec4_to_vec3(t_vec4 v)
{
	t_vec3	res;

	res.x = v.x;
	res.y = v.y;
	res.z = v.z;
	return (res);
}
