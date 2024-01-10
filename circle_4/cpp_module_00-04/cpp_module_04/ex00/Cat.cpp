/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:31 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:49:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.h"

Cat::Cat()
	: Animal()
{
	m_Type = "Cat";
	std::cout << "Cat default constructor called\n";

}

Cat::Cat(const Cat& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "Cat assignment operator called\n";
	return *this;
}

std::string Cat::getType() const
{
	std::cout << "Cat getType\n";
	return m_Type;
}

void Cat::makeSound() const
{
	std::cout << "Meooooowwwwwwww~\n";
}