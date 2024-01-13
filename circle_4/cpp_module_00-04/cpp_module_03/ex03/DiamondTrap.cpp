/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:32:35 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 16:05:51 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
	: ClapTrap("None_clap_name"), ScavTrap(), FragTrap()
{
	m_Name = "None";
	m_HitPoint = 100;
	m_EnergyPoint = 50;
	m_AttackDamage = 30;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	m_Name = name;
	m_HitPoint = 100;
	m_EnergyPoint = 50;
	m_AttackDamage = 30;
	std::cout << "DiamondTrap constructor called\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
	: ClapTrap(), ScavTrap(), FragTrap()
{
	*this = rhs;
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
	m_HitPoint = rhs.m_HitPoint;
	m_EnergyPoint = rhs.m_EnergyPoint;
	m_AttackDamage = rhs.m_AttackDamage;
	std::cout << "ClapTrap copy assignment operator called\n";
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	if (isAlive() == false)
		return;

	std::cout
		<< "DiamondTrap Name: "
		<< m_Name
		<< std::endl;
	std::cout
		<< "ScavTrap Name: "
		<< ScavTrap::m_Name
		<< std::endl;
	m_EnergyPoint--;
}

void DiamondTrap::printStatus()
{
	std::cout << "Dia Name : " << m_Name << std::endl;
	std::cout << "Clap Name : " << ClapTrap::m_Name << std::endl;
	std::cout << "HP : " << m_HitPoint << std::endl;
	std::cout << "Energy : " << m_EnergyPoint << std::endl;
	std::cout << "Damage : " << m_AttackDamage << std::endl;
}

bool DiamondTrap::isAlive()
{
	if (m_EnergyPoint <= 0 || m_HitPoint <= 0)
	{
		std::cout << "DiamondTrap is already dead\n";
		return false;
	}
	return true;
}