/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihwjeon <jihwjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:28:24 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/08 17:07:00 by jihwjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmath.h"

t_vec2	make_vec2(double x, double y)
{
	t_vec2	res;

	res.x = x;
	res.y = y;
	return (res);
}

t_uv	make_uv(double u, double v)
{
	t_vec2	res;

	res.u = u;
	res.v = v;
	return (res);
}

t_vec2	vec2_plus_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	res;

	res.x = (v1.x + v2.x);
	res.y = (v1.y + v2.y);
	return (res);
}

t_vec2	vec2_minus_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	res;

	res.x = (v1.x - v2.x);
	res.y = (v1.y - v2.y);
	return (res);
}

t_vec2	vec2_multiply_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	res;

	res.x = (v1.x * v2.x);
	res.y = (v1.y * v2.y);
	return (res);
}
