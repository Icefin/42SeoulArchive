/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:11:40 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 10:14:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: m_Name(name)
{
	//__noop;
}

HumanB::~HumanB()
{
	//__noop;
}

void HumanB::attack()
{
	if (m_Weapon == nullptr)
	{
		std::cout
			<< m_Name
			<< " doesn't have any weapon\n";
		return;
	}

	std::cout
		<< m_Name
		<< " attacks with their "
		<< m_Weapon->getType()
		<< std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	m_Weapon = &weapon;
}