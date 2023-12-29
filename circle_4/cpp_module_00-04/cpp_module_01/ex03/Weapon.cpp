/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:11:23 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 17:40:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
	: m_Type(type)
{

}

Weapon::~Weapon(void)
{
	std::cout << "Weapon has been destroyed\n";
}

const std::string& Weapon::getType(void) const
{
	return m_Type;
}

void Weapon::setType(std::string type)
{
	m_Type = type;
}