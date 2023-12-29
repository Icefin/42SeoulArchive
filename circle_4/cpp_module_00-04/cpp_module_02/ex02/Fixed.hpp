/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:31 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/29 17:05:37 by singeonho        ###   ########.fr       */
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

	Fixed& operator>(const Fixed& rhs);
	Fixed& operator<(const Fixed& rhs);
	Fixed& operator>=(const Fixed& rhs);
	Fixed& operator<=(const Fixed& rhs);
	Fixed& operator==(const Fixed& rhs);
	Fixed& operator!=(const Fixed& rhs);

	Fixed& operator+(const Fixed& rhs);
	Fixed& operator-(const Fixed& rhs);
	Fixed& operator*(const Fixed& rhs);
	Fixed& operator/(const Fixed& rhs);

public :
	static Fixed& min(Fixed& f1, Fixed& f2);
	static Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static Fixed& max(const Fixed& f1, const Fixed& f2);

private :
	static const int s_FractionalBits = 8;
	int m_Value;
};

std::ostream& operator<<(std::ostream& out, const Fixed& rhs);

#endif