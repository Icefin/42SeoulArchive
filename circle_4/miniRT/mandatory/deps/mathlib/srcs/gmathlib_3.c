/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:36:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 22:59:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

double	dot_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}


t_vec3	cross_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	res;
	//__noop;
	return (res);
}



t_vec3	reflect_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	res;
	//__noop;
	return (res);
}