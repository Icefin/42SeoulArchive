/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:23:35 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 17:02:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public :
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& rhs);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toInt(void) const;
	float toFloat(void) const;

	Fixed& operator=(const Fixed& rhs);

private :
	static const int s_FractionalBits = 8;
	int m_Value;
};

std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

#endif