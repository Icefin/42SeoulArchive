/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:16:58 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 15:27:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.h"

FragTrap::FragTrap()
	: ClapTrap()
{
	m_HitPoint = 100;
	m_EnergyPoint = 100;
	m_AttackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}
	
FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	m_HitPoint = 100;
	m_EnergyPoint = 100;
	m_AttackDamage = 30;
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap& rhs)
	: ClapTrap(rhs)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	m_Name = rhs.m_Name;
	m_HitPoint = rhs.m_HitPoint;
	m_EnergyPoint = rhs.m_EnergyPoint;
	m_AttackDamage = rhs.m_AttackDamage;
	std::cout << "FragTrap copy assignment operator called\n";
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (isAlive() == false)
		return ;

	std::cout 
		<< "FragTrap "
		<< m_Name
		<< " attacks "
		<< target
		<< ", causing "
		<< m_AttackDamage
		<< " points of damage!\n";
	m_EnergyPoint--;
}

void FragTrap::highFivesGuys()
{
	if (isAlive() == false)
		return ;
	
	std::cout 
		<< "FragTrap "
		<< m_Name
		<< " requests a positive high fives!\n";
	m_EnergyPoint--;
}

bool FragTrap::isAlive()
{
	if (m_EnergyPoint <= 0 || m_HitPoint <= 0)
	{
		std::cout << "FragTrap is already dead\n";
		return false;
	}
	return true;
}