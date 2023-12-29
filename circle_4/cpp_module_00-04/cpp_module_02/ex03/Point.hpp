/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:24 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 16:57:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public :
	Point(void);
	Point(const float x, const float y);
	Point(const Point& rhs);
	~Point(void);

	Point& operator=(const Point& rhs);

private :
	Fixed m_X;
	Fixed m_Y;
};


#endif