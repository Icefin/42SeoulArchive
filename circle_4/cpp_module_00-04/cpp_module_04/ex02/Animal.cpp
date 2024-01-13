/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:31 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:11:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.h"

Animal::Animal()
	: m_Type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& rhs)
	: m_Type(rhs.m_Type)
{
	std::cout << "Animal copy constructor called\n";
}
Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& rhs)
{
	m_Type = rhs.m_Type;
	std::cout << "Animal assignment operator called\n";
	return *this;
}

std::string Animal::getType() const
{
	std::cout << "Animal getType\n";
	return m_Type;
}