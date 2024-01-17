/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:58 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 15:35:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm::GradeTooHigh";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm::GradeTooLow";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return "AForm::UnsignedForm";
}

const char* AForm::SignedFormException::what() const throw()
{
	return "AForm::SignedForm";
}

AForm::AForm()
	: m_Name("Default"), m_Target("None"), m_IsSigned(false), m_SignGrade(AForm::s_MinGrade), m_ExecuteGrade(AForm::s_MinGrade)
{
	//__noop;
}

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade)
	: m_Name(name), m_Target("None"), m_IsSigned(false), m_SignGrade(signGrade), m_ExecuteGrade(executeGrade)
{
	if (m_SignGrade < AForm::s_MaxGrade)
		throw(AForm::GradeTooHighException());
	if (m_SignGrade > AForm::s_MinGrade)
		throw(AForm::GradeTooLowException());

	if (m_ExecuteGrade < AForm::s_MaxGrade)
		throw(AForm::GradeTooHighException());
	if (m_ExecuteGrade > AForm::s_MinGrade)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const std::string& name, const std::string& target, const int signGrade, const int executeGrade)
	: m_Name(name), m_Target(target), m_IsSigned(false), m_SignGrade(signGrade), m_ExecuteGrade(executeGrade)
{
	if (m_SignGrade < AForm::s_MaxGrade)
		throw(AForm::GradeTooHighException());
	if (m_SignGrade > AForm::s_MinGrade)
		throw(AForm::GradeTooLowException());

	if (m_ExecuteGrade < AForm::s_MaxGrade)
		throw(AForm::GradeTooHighException());
	if (m_ExecuteGrade > AForm::s_MinGrade)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm& op)
	: m_Name(op.m_Name), m_Target(op.m_Target), m_IsSigned(op.m_IsSigned), m_SignGrade(op.m_SignGrade), m_ExecuteGrade(op.m_ExecuteGrade)
{
	//__noop;
}

AForm::~AForm()
{
	//__noop;
}

AForm& AForm::operator=(const AForm& op)
{
	const_cast<std::string&>(m_Name) = op.m_Name;
	m_Target = op.m_Target;
	m_IsSigned = op.m_IsSigned;
	const_cast<int&>(m_SignGrade) = op.m_SignGrade;
	const_cast<int&>(m_ExecuteGrade) = op.m_ExecuteGrade;
	return *this;
}

std::string AForm::getName() const
{
	return m_Name;
}

std::string AForm::getTarget() const
{
	return m_Target;
}

bool AForm::getIsSigned() const
{
	return m_IsSigned;
}

int AForm::getSignGrade() const
{
	return m_SignGrade;
}

int AForm::getExecuteGrade() const
{
	return m_ExecuteGrade;
}

void AForm::checkSignable(const Bureaucrat& bureaucrat) const
{
	if (m_IsSigned == true)
		throw(AForm::SignedFormException());
	if (m_SignGrade < bureaucrat.getGrade())
		throw(AForm::GradeTooLowException());
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	checkSignable(bureaucrat);
	m_IsSigned = true;
}

void AForm::checkExecutable(const Bureaucrat& executor) const
{
	if (m_IsSigned == false)
		throw(AForm::UnsignedFormException());
	if (m_ExecuteGrade < executor.getGrade())
		throw(AForm::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const AForm& op)
{
	return os << op.getName() << ", is signed (" << op.getIsSigned() << "), sign grade: " << op.getSignGrade() << ", execute grade: " << op.getExecuteGrade() << std::endl;
}