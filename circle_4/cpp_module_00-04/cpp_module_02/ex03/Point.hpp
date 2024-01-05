/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:24 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 17:24:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public :
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point(const Point& rhs);
	~Point(void);

	Fixed getX(void) const;
	Fixed getY(void) const;

	Point& operator=(const Point& rhs);

	Point operator+(const Point& rhs) const;
	Point operator-(const Point& rhs) const;

public :
	static Fixed dot(const Point& p1, const Point& p2);
	static Fixed cross(const Point& p1, const Point& p2);

private :
	Fixed m_X;
	Fixed m_Y;
};


#endif