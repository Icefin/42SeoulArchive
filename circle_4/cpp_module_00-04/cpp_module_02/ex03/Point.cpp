/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:52:49 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 17:23:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Point::Point(void)
	: m_X(0), m_Y(0)
{
	std::cout << "Default constructor called\n";
}

Point::Point(const Fixed x, const Fixed y)
	: m_X(x), m_Y(y)
{
	std::cout << "Parameter constructor called\n";
}

Point::Point(const Point& rhs)
	: m_X(rhs.getX()), m_Y(rhs.getY())
{
	std::cout << "Copy constructor called\n";
}

Point::~Point(void)
{
	std::cout << "Destructor called\n";
}

Fixed Point::getX(void) const
{
	return m_X;
}

Fixed Point::getY(void) const
{
	return m_Y;
}

Point& Point::operator=(const Point& rhs)
{
	std::cout << "Copy assignment operator called\n";
	m_X = rhs.getX();
	m_Y = rhs.getY();
	return *this;
}

Fixed Point::dot(const Point& p1, const Point& p2)
{
	return (p1.getX() * p2.getX() + p1.getY() * p2.getY());
}

Fixed Point::cross(const Point& p1, const Point& p2)
{
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}

Point Point::operator+(const Point& rhs) const
{
	return Point(m_X + rhs.getX(), m_Y + rhs.getY());
}

Point Point::operator-(const Point& rhs) const
{
	return Point(m_X - rhs.getX(), m_Y - rhs.getY());
}
