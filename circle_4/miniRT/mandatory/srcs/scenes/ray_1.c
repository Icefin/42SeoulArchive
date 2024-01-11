/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:39:32 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/01 22:43:33 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_rayinfo(t_rayinfo *rayinfo, float maxtime)
{
	if (rayinfo == 0)
		return ;
	rayinfo->raytime = maxtime;
	rayinfo->hitid = -1;
}

t_rayinfo	make_rayinfo(float raytime, t_vec3 hitpos, t_vec3 hitnorm)
{
	t_rayinfo	info;

	info.raytime = raytime;
	info.hitpos = hitpos;
	info.hitnorm = hitnorm;
	return (info);
}

t_ray	make_ray(t_vec3 origin, t_vec3 direction, float maxdist)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.maxdist = maxdist;
	return (ray);
}
