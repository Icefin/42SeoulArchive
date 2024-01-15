/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:31 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:04:51 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.h"

Cat::Cat()
	: Animal()
{
	m_Type = "Cat";
	m_Brain = new Brain();
	std::cout << "Cat default constructor called\n";

}

Cat::Cat(const Cat& rhs)
	: Animal()
{
	*this = rhs;
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
	delete m_Brain;
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	m_Type = rhs.m_Type;
	*m_Brain = *(rhs.m_Brain);
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

void Cat::printIdeaSource() const
{
	std::cout << "IdeaSource: " << &(m_Brain->getIdea(0)) << std::endl;
}