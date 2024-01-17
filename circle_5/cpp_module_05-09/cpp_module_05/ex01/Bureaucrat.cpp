/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:54:05 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:03:53 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::GradeTooHigh";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::GradeTooLow";
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
		throw(Bureaucrat::GradeTooHighException());
	if (m_Grade > MIN_GRADE)
		throw(Bureaucrat::GradeTooLowException());
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
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decreaseGrade()
{
	m_Grade++;
	if (m_Grade > MIN_GRADE)
		throw(Bureaucrat::GradeTooLowException());
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << m_Name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << m_Name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& op)
{
	return os << op.getName() << ", bureaucrat grade " << op.getGrade() << ".\n";
}