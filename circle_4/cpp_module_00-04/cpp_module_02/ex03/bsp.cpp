/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:09 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/30 22:43:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	glm::vec3 pa = triangle.p1 - point;
	glm::vec3 pb = triangle.p2 - point;
	glm::vec3 pc = triangle.p3 - point;

	glm::vec3 u = glm::cross(pa, pc);
	glm::vec3 v = glm::cross(pc, pa);
	glm::vec3 w = glm::cross(pa, pb);

	if (glm::dot(u, v) < 0.0f)
		return false;
	if (glm::dot(u, w) < 0.0f)
		return false;
	return true;
}