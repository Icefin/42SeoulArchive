/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:23 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:07:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.h"

Dog::Dog()
	: Animal()
{
	m_Type = "Dog";
	m_Brain = new Brain();
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
	delete m_Brain;
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& rhs)
{
	m_Type = rhs.m_Type;
	*m_Brain = *(rhs.m_Brain);
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

void Dog::printIdeaSource() const
{
	std::cout << "IdeaSource: " << &(m_Brain->getIdea(0)) << std::endl;
}