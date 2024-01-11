/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:34 by geshin            #+#    #+#             */
/*   Updated: 2023/12/25 12:51:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

//glm::reflect
//incident - 2.0 * dot(incident, normal) * normal;
t_vec3	reflect_vec3(t_vec3 i, t_vec3 n)
{
	return vec3_minus_vec3(i, vec3_multiply_num(n, 2.0 * dot_vec3(n, i)));
}