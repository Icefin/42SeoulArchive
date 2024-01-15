/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:55:20 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:59:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.h"

Cure::Cure()
	: AMateria()
{
	m_Type = "cure";
}
	
Cure::Cure(const Cure& rhs)
	: AMateria()
{
	*this = rhs;
}

Cure::~Cure()
{
	//__noop;
}

Cure& Cure::operator=(const Cure& rhs)
{
	m_Type = rhs.m_Type;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout
		<< "* heals "
		<< target.getName()
		<< "'s wounds *\n";
}