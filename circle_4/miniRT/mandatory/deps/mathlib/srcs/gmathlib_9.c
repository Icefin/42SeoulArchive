/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmathlib_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:37:14 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/07 23:01:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmathlib.h"

t_quat	make_quat(double w, double x, double y, double z)
{
	t_quat	res;

	res.w = w;
	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vec3	quat_to_euler(const t_quat *quat)
{
	t_vec3	res;
	//__noop;
	return (res);
}

t_quat	euler_to_quat(const t_vec3 *euler)
{
	t_quat	res;
	//__noop;
	return (res);
}