/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:15 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:09:06 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.h"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	m_HitPoint = 100;
	m_EnergyPoint = 50;
	m_AttackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	m_HitPoint = 100;
	m_EnergyPoint = 50;
	m_AttackDamage = 20;
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
	: ClapTrap(rhs)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	m_Name = rhs.m_Name;
	m_HitPoint = rhs.m_HitPoint;
	m_EnergyPoint = rhs.m_EnergyPoint;
	m_AttackDamage = rhs.m_AttackDamage;
	std::cout << "ScavTrap copy assignment operator called\n";
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (isAlive() == false)
		return ;

	std::cout 
		<< "ScavTrap "
		<< m_Name
		<< " attacks "
		<< target
		<< ", causing "
		<< m_AttackDamage
		<< " points of damage!\n";
	m_EnergyPoint--;
}

void ScavTrap::guardGate()
{
	if (isAlive() == false)
		return ;
	
	std::cout
		<< "ScavTrap "
		<< m_Name
		<< " is now in Gate keeper mode.\n";
	m_EnergyPoint--;
}

bool ScavTrap::isAlive()
{
	if (m_EnergyPoint <= 0 || m_HitPoint <= 0)
	{
		std::cout << "ScavTrap is already dead\n";
		return false;
	}
	return true;
}