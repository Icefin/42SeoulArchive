/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:34 by geshin            #+#    #+#             */
/*   Updated: 2024/01/12 19:46:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtmath.h"

//glm::reflect
//incident - 2.0 * dot(incident, normal) * normal;
t_vec3	reflect_vec3(t_vec3 i, t_vec3 n)
{
	return vec3_minus_vec3(i, vec3_multiply_num(n, 2.0 * dot_vec3(n, i)));
}

t_vec3	refract_vec3(t_vec3 i, t_vec3 n, double n1, double n2)
{
	double snell = n1 / n2;
	double cosi = -dot_vec3(n, i);
	double sint2 = snell * snell * (1.0 - cosi * cosi);
	if (sint2 > 1.0)
		return make_vec3(0, 0, 0);
	double cost = sqrt(1.0 - sint2);
	return vec3_plus_vec3(vec3_multiply_num(i, snell), vec3_multiply_num(n, (snell * cosi - cost)));
}