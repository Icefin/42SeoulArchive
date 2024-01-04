/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 23:27:12 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec2.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	Point pa = p - a;
	Point pb = p - a;
	Point pc = p - c;

	Fixed u = Point::cross(pa, pc);
	Fixed v = Point::cross(pc, pa);
	Fixed w = Point::cross(pa, pb);

	if (u.toFloat() > 0 && v.toFloat() > 0 && w.toFloat() > 0)
		return true;
	if (u.toFloat() < 0 && v.toFloat() < 0 && w.toFloat() < 0)
		return true;
	return false;
}