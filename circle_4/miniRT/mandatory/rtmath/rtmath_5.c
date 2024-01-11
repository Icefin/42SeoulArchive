/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:08:34 by geshin            #+#    #+#             */
/*   Updated: 2024/01/08 17:08:03 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

//glm::reflect
//incident - 2.0 * dot(incident, normal) * normal;
t_vec3	reflect_vec3(t_vec3 i, t_vec3 n)
{
	return (vec3_minus_vec3(i, vec3_multiply_num(n, 2.0 * dot_vec3(n, i))));
}
