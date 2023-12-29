/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:37:16 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 15:52:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "commontype.h"
# include "rtmath.h"

typedef struct s_rayinfo
{
	float 	raytime;
	t_vec3 	hitpos;
	t_vec3 	hitnorm;

	int		hitid;
}	t_rayinfo;

void		init_rayinfo(t_rayinfo *rayinfo, float maxtime);
t_rayinfo	make_rayinfo(float raytime, t_vec3 hitpos, t_vec3 hitnorm);

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	float	maxdist;
}	t_ray;

t_ray	make_ray(t_vec3 origin, t_vec3 direction, float maxdist);

#endif