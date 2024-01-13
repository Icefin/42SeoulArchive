/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:00 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:29:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria()
{
	//__noop;
}

AMateria::AMateria(const std::string& type)
	: m_Type(type)
{
	//__noop;
}

AMateria::AMateria(const AMateria& rhs)
{
	*this = rhs;
}

AMateria::~AMateria()
{
	//__noop;
}

const std::string& AMateria::getType() const
{
	return m_Type;	
}
	
void AMateria::use(ICharacter& target)
{
	
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	m_Type = rhs.m_Type;
	return *this;
}