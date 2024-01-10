/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:17 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:44:28 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
	: m_Type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
	: m_Type(rhs.m_Type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "WrongAnimal assignment operator called\n";
	return *this;
}

std::string WrongAnimal::getType() const
{
	return m_Type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Who am I...?\n";
}