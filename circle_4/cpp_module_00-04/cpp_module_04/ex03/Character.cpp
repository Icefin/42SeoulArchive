/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:36:00 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:53:41 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.h"
#include "Character.h"

Character::Character()
{
	m_Name = "None";
	m_MateriaNum = 0;
}

Character::Character(const std::string& name)
{
	m_Name = name;
	m_MateriaNum = 0;
}

Character::Character(const Character& rhs)
{
	*this = rhs;
}

Character::~Character()
{
	for (int i = 0; i < m_MateriaNum; ++i)
		delete m_Inventory[i];
}

Character& Character::operator=(const Character& rhs)
{
	for (int i = 0; i < m_MateriaNum; ++i)
		delete m_Inventory[i];

	m_Name = rhs.m_Name;
	m_MateriaNum = rhs.m_MateriaNum;
	for (int i = 0; i < m_MateriaNum; ++i)
		m_Inventory[i] = rhs.m_Inventory[i]->clone();
	return *this;
}

const std::string& Character::getName() const
{
	return m_Name;	
}

void Character::equip(AMateria* m)
{
	if (m_MateriaNum == INVENTORY_SIZE)
	{
		std::cout << "Inventory is already full\n";
		return;
	}
	m_Inventory[m_MateriaNum++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= m_MateriaNum)
	{
		std::cout << "Incorrect inventory idx\n";
		return;
	}
	AMateria* temp = m_Inventory[idx];
	m_Inventory[idx] = m_Inventory[m_MateriaNum - 1];
	m_Inventory[m_MateriaNum - 1] = NULL;
	delete temp;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= m_MateriaNum)
	{
		std::cout << "Incorrect inventory idx\n";
		return;
	}
	m_Inventory[idx]->use(target);
}