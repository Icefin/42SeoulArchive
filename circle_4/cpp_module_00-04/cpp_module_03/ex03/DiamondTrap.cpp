/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:32:35 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:07:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
	: ClapTrap("None_clap_name"), ScavTrap(), FragTrap(), m_Name("None")
{
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), m_Name(name)
{
	std::cout << "DiamondTrap constructor called\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
{
	m_Name = rhs.m_Name;
	ClapTrap::m_Name = rhs.ClapTrap::m_Name;
	FragTrap::m_HitPoint = rhs.FragTrap::m_HitPoint;
	ScavTrap::m_EnergyPoint = rhs.ScavTrap::m_EnergyPoint;
	FragTrap::m_AttackDamage = rhs.FragTrap::m_AttackDamage;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	m_Name = rhs.m_Name;
	ClapTrap::m_Name = rhs.ClapTrap::m_Name;
	FragTrap::m_HitPoint = rhs.FragTrap::m_HitPoint;
	ScavTrap::m_EnergyPoint = rhs.ScavTrap::m_EnergyPoint;
	FragTrap::m_AttackDamage = rhs.FragTrap::m_AttackDamage;
	std::cout << "ClapTrap copy assignment operator called\n";
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout
		<< "DiamondTrap Name: "
		<< m_Name
		<< std::endl;
	std::cout
		<< "ScavTrap Name: "
		<< ScavTrap::m_Name
		<< std::endl;
	ScavTrap::m_EnergyPoint--;
}

bool DiamondTrap::isAlive()
{
	if (ScavTrap::m_EnergyPoint <= 0 || FragTrap::m_HitPoint <= 0)
	{
		std::cout << "DiamondTrap is already dead\n";
		return false;
	}
	return true;
}