/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:28 by geshin            #+#    #+#             */
/*   Updated: 2024/01/08 17:07:07 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_vec2	vec2_multiply_num(t_vec2 v, double num)
{
	t_vec2	res;

	res.x = v.x * num;
	res.y = v.y * num;
	return (res);
}

void	clamp_vec2(t_vec2 *out, double min, double max)
{
	if (out->x < min)
		out->x = min;
	else if (out->x > max)
		out->x = max;
	if (out->y < min)
		out->y = min;
	else if (out->y > max)
		out->y = max;
}

double	dot_vec2(t_vec2 v1, t_vec2 v2)
{
	double	res;

	res = (v1.x * v2.x) + (v1.y * v2.y);
	return (res);
}
