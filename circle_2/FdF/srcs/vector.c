/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:20:08 by geshin            #+#    #+#             */
/*   Updated: 2023/09/09 01:18:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vec3	make_vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec4	make_vec4(double x, double y, double z, double w)
{
	t_vec4 res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}

void	normalize_vec3(t_vec3* v)
{
	double w = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));

	v->x /= w;
	v->y /= w;
	v->z /= w;
}

double	dot_product(const t_vec3 v1, const t_vec3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vec3	cross_product(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}