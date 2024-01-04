/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:53:14 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 21:51:41 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
	: m_Value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	m_Value = (value << s_FractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	m_Value = roundf(value * (1 << s_FractionalBits));
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called\n";
	m_Value = rhs.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return m_Value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	m_Value = raw;
}

float Fixed::toInt(void) const
{
	return (m_Value >> s_FractionalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)m_Value / (1 << s_FractionalBits));
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called\n";
	m_Value = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	return out << rhs.toFloat();
}