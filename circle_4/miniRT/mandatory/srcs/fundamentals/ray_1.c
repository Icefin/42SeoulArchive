/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:07:56 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/13 19:09:27 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_rayinfo	make_rayinfo(float raytime, t_vec3 hitpos, t_vec3 hitnorm, t_int32 id)
{
	t_rayinfo	res;

	res.raytime = raytime;
	res.hit_position = hitpos;
	res.hit_normal = hitnorm;
	res.object_id = id;
	return (res);
}

t_ray	make_ray(t_vec3	origin, t_vec3	direction)
{
	t_ray res;

	res.origin = origin;
	res.direction = direction;
	return (res);
}