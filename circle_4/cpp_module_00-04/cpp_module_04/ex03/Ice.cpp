/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:55:15 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:59:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.h"

Ice::Ice()
	: AMateria()
{
	m_Type = "ice";
}

Ice::Ice(const Ice& rhs)
	: AMateria()
{
	*this = rhs;
}

Ice::~Ice()
{
	//__noop;
}

Ice& Ice::operator=(const Ice& rhs)
{
	m_Type = rhs.m_Type;
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout
		<< "* shoots an ice bolt at "
		<< target.getName()
		<< " *\n";
}