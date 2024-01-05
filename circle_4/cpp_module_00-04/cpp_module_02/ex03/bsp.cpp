/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 17:33:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	Point pa = p - a;
	Point pb = p - b;
	Point pc = p - c;

	Fixed u = Point::cross(pa, pb);
	Fixed v = Point::cross(pb, pc);
	Fixed w = Point::cross(pc, pa);

	if (u.toFloat() * v.toFloat() > 0.0f && u.toFloat() * w.toFloat() > 0.0f)
		return true;
	return false;
}