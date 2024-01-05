/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:53:19 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/05 17:14:55 by singeonho        ###   ########.fr       */
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
	return m_Value;
}

void Fixed::setRawBits(const int raw)
{
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

bool Fixed::operator>(const Fixed& rhs) const
{
	return m_Value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return m_Value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return m_Value >= rhs.getRawBits();
}
bool Fixed::operator<=(const Fixed& rhs) const
{
	return m_Value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return m_Value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return m_Value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.getRawBits() == 0)
		throw(std::runtime_error("Divide by zero"));
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++(void)
{
	m_Value++;
	return *this;
}

Fixed Fixed::operator--(void)
{
	m_Value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed res(this->toFloat());
	m_Value++;
	return res;
}

Fixed Fixed::operator--(int)
{
	Fixed res(this->toFloat());
	m_Value--;
	return res;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.toFloat() < f2.toFloat())
		return f1;
	return f1;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.toFloat() < f2.toFloat())
		return f2;
	return f1;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.toFloat() < f2.toFloat())
		return f2;
	return f1;
}

std::ostream& operator<<(std::ostream& out, const Fixed& rhs)
{
	return out << rhs.toFloat();
}