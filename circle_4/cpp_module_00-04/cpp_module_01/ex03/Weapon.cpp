/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:11:23 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/27 10:44:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: m_Type(type)
{

}

Weapon::Weapon(void)
{
	//__noop;
}

Weapon::~Weapon(void)
{
	//__noop;
}

const std::string& Weapon::getType(void) const
{
	return m_Type;
}

void Weapon::setType(std::string type)
{
	m_Type = type;
}