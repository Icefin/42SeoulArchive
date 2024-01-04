/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:10:19 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/30 23:21:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_HPP
# define VEC2_HPP

# include "Point.hpp"

class Vec2
{
public :
	Vec2(void);
	Vec2(const Vec2& rhs);
	~Vec2(void);

	Vec2& operator=(const Vec2& rhs);

public :
	static float cross(const Vec2& l, const Vec2& r);

private :
	float m_X;
	float m_Y;
};

#endif