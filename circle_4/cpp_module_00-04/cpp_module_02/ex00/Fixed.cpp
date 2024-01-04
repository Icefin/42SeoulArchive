/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:27:39 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/02 12:59:15 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
	: m_Value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called\n";
	m_Value = rhs.m_Value;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
	//__noop;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (m_Value >> s_FractionalBits);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	m_Value = (raw << s_FractionalBits);
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called\n";
	m_Value = rhs.m_Value;
}