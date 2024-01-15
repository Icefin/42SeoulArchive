/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:23 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:11:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.h"

Dog::Dog()
	: Animal()
{
	m_Type = "Dog";
	std::cout << "Dog default constructor called\n";

}

Dog::Dog(const Dog& rhs)
	: Animal()
{
	*this = rhs;
	std::cout << "Dog copy constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "Dog assignment operator called\n";
	return *this;
}

std::string Dog::getType() const
{
	std::cout << "Dog getType\n";
	return m_Type;
}

void Dog::makeSound() const
{
	std::cout << "Woooooooooooof!\n";
}