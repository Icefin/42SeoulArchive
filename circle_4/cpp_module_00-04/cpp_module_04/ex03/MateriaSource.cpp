/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:51:10 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:55:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
	m_TemplateNum = 0;
	std::memset(m_Templates, 0, sizeof(m_Templates));
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	m_TemplateNum = rhs.m_TemplateNum;
	memcpy(m_Templates, rhs.m_Templates, MATERIA_SIZE * sizeof(AMateria));
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < m_TemplateNum; ++i)
		delete m_Templates[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{

	m_TemplateNum = rhs.m_TemplateNum;
	memcpy(m_Templates, rhs.m_Templates, MATERIA_SIZE * sizeof(AMateria));
	return *this;
}

void MateriaSource::learnMateria(AMateria* elem)
{
	if (m_TemplateNum == MATERIA_SIZE)
	{
		std::cout << "MateriaSource has already learned 4 AMateria\n";
		return ;
	}

	m_Templates[m_TemplateNum++] = elem;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < m_TemplateNum; ++i) {
		if (m_Templates[i]->getType() == type)
			return m_Templates[i]->clone();
	}
	std::cout << "MateriaSource doesn't learn " << type << " type of AMateria\n";
	return NULL;
}