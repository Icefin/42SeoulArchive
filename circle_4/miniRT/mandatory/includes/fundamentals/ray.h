/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:29:45 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/10 12:05:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "commontype.h"
# include "gmathlib.h"

typedef struct s_rayinfo
{
	float	raytime;
	t_vec3	hit_position;
	t_vec3	hit_normal;

	t_int32	object_id;
}	t_rayinfo;

t_rayinfo	make_rayinfo(float raytime, t_vec3 hitpos, t_vec3 hirnom, t_int32 id);

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

t_ray	make_ray(t_vec3	origin, t_vec3	direction);

#endif