/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:51:10 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/12 18:52:09 by singeonho        ###   ########.fr       */
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
	memcpy(m_Templates, rhs.m_Templates, s_TemplateMax * sizeof(AMateria));
}

MateriaSource::~MateriaSource()
{
	delete[] m_Templates;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{

	m_TemplateNum = rhs.m_TemplateNum;
	memcpy(m_Templates, rhs.m_Templates, s_TemplateMax * sizeof(AMateria));
	return *this;
}

void MateriaSource::learnMateria(AMateria* elem)
{
	if (m_TemplateNum == s_TemplateMax)
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