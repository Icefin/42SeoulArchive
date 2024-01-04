/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/30 23:19:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec2.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	Vec2 pa = p - a;
	Vec2 pb = p - a;
	Vec2 pc = p - c;

	float u = Vec2::cross(pa, pc);
	float v = Vec2::cross(pc, pa);
	float w = Vec2::cross(pa, pb);

	if (u > 0 && v > 0 && w > 0)
		return true;
	if (u < 0 && v < 0 && w < 0)
		return true;
	return false;
}