/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:20:08 by geshin            #+#    #+#             */
/*   Updated: 2023/06/13 15:30:48 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vec2	make_vec2(int x, int y)
{
	t_vec2	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_vec3	make_vec3(int x, int y, int z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
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

/*
t_vec2	project_to_plane(t_vec3 normal, t_vec3 origin, t_vec3 point)
{
	t_vec2 res;

	
	return (res);
}
*/