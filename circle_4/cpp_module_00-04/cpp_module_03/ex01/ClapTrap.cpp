/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:10 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 16:02:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.h"

ClapTrap::ClapTrap()
	: m_Name("None"), m_HitPoint(10), m_EnergyPoint(10), m_AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: m_Name(name), m_HitPoint(10), m_EnergyPoint(10), m_AttackDamage(0)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	*this = rhs;
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	m_Name = rhs.m_Name;
	m_HitPoint = rhs.m_HitPoint;
	m_EnergyPoint = rhs.m_EnergyPoint;
	m_AttackDamage = rhs.m_AttackDamage;
	std::cout << "ClapTrap copy assignment operator called\n";
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (isAlive() == false)
		return ;

	std::cout 
		<< "ClapTrap "
		<< m_Name
		<< " attacks "
		<< target
		<< ", causing "
		<< m_AttackDamage
		<< " points of damage!\n";
	m_EnergyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isAlive() == false)
		return ;

	std::cout 
		<< "ClapTrap "
		<< m_Name
		<< " takes "
		<< amount
		<< " points of damage!\n";
	m_HitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isAlive() == false)
		return ;

	std::cout 
		<< "ClapTrap "
		<< m_Name
		<< " is repaired "
		<< amount
		<< " points!\n";
	m_HitPoint += amount;
	m_EnergyPoint--;
}

bool ClapTrap::isAlive()
{
	if (m_EnergyPoint <= 0 || m_HitPoint <= 0)
	{
		std::cout << "ClapTrap is already dead\n";
		return false;
	}
	return true;
}