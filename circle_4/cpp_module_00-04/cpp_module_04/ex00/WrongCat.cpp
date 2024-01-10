/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:15 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:54:43 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.h"

WrongCat::WrongCat()
{
	m_Type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "WrongCat copy constructor called\n";
}
	
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "WrongCat assignment operator called\n";
	return *this;
}

std::string WrongCat::getType() const
{
	return m_Type;
}

void WrongCat::makeSound() const
{
	std::cout << "Meooooowwwwwwww~\n";
}