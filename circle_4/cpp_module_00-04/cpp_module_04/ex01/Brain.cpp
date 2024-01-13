/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:19:15 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 16:54:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.h"

Brain::Brain()
{
	for (int i = 0; i < IDEA_SIZE; ++i)
		m_Ideas[i] = "IDEA";
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& rhs)
{
	*this = rhs;
	std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i < IDEA_SIZE; ++i)
		m_Ideas[i] = rhs.m_Ideas[i];
	return *this;
}

const std::string& Brain::getIdea(int idx) const
{
	if (idx < 0 || idx > IDEA_SIZE)
		std::runtime_error("Brain out of range...\n");
	return m_Ideas[idx];
}

void Brain::setIdea(int idx, const std::string& idea)
{
	if (idx < 0 || idx > IDEA_SIZE)
		std::runtime_error("Brain out of range...\n");
	m_Ideas[idx] = idea;
}