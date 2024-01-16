/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:54:05 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/16 23:05:17 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHigh Exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLow Exception";
}

Bureaucrat::Bureaucrat()
	: m_Name("Default"), m_Grade(MIN_GRADE)
{
	//__noop;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: m_Name(name), m_Grade(grade)
{
	if (m_Grade < MAX_GRADE)
		throw(GradeTooHighException());
	if (m_Grade > MIN_GRADE)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& op)
	: m_Name(op.m_Name), m_Grade(op.m_Grade)
{
	//__noop;
}

Bureaucrat::~Bureaucrat()
{
	//__noop;
}
	
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& op)
{
	const_cast<std::string&>(m_Name) = op.m_Name;
	m_Grade = op.m_Grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return m_Name;
}

int Bureaucrat::getGrade() const
{
	return m_Grade;
}

void Bureaucrat::increaseGrade()
{
	m_Grade--;
	if (m_Grade < MAX_GRADE)
		throw(GradeTooHighException());
}

void Bureaucrat::decreaseGrade()
{
	m_Grade++;
	if (m_Grade > MIN_GRADE)
		throw(GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& op)
{
	return os << op.getName() << ", bureaucrat grade " << op.getGrade() << ".\n";
}