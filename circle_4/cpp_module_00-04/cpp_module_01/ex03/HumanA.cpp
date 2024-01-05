/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:11:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/06 01:53:34 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
	: m_Name(name), m_Weapon(weapon)
{
	//__noop;
}

HumanA::~HumanA()
{
	//__noop;
}

void HumanA::attack()
{
	std::cout
		<< m_Name
		<< " attacks with their "
		<< m_Weapon.getType()
		<< std::endl;
}