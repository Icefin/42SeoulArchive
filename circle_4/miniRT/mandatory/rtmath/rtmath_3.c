/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:33 by geshin            #+#    #+#             */
/*   Updated: 2024/01/08 17:07:32 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

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

t_vec3	vec3_plus_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.x + v2.x);
	res.y = (v1.y + v2.y);
	res.z = (v1.z + v2.z);
	return (res);
}

t_vec3	vec3_minus_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.x - v2.x);
	res.y = (v1.y - v2.y);
	res.z = (v1.z - v2.z);
	return (res);
}

t_vec3	vec3_multiply_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.x * v2.x);
	res.y = (v1.y * v2.y);
	res.z = (v1.z * v2.z);
	return (res);
}
