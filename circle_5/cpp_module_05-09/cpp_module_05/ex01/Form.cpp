/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:13:02 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:37:13 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHigh";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLow";
}

Form::Form()
	: m_Name("Default"), m_IsSigned(false), m_SignGrade(MIN_GRADE), m_ExecuteGrade(MIN_GRADE)
{
	//__noop;
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
	: m_Name(name), m_IsSigned(false), m_SignGrade(signGrade), m_ExecuteGrade(executeGrade)
{
	if (m_SignGrade < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (m_SignGrade > MIN_GRADE)
		throw(Form::GradeTooLowException());

	if (m_ExecuteGrade < MAX_GRADE)
		throw(Form::GradeTooHighException());
	if (m_ExecuteGrade > MIN_GRADE)
		throw(Form::GradeTooLowException());
}

Form::Form(const Form& op)
	: m_Name(op.m_Name), m_IsSigned(op.m_IsSigned), m_SignGrade(op.m_SignGrade), m_ExecuteGrade(op.m_ExecuteGrade)
{
	//__noop;
}

Form::~Form()
{
	//__noop;
}

Form& Form::operator=(const Form& op)
{
	const_cast<std::string&>(m_Name) = op.m_Name;
	m_IsSigned = op.m_IsSigned;
	const_cast<int&>(m_SignGrade) = op.m_SignGrade;
	const_cast<int&>(m_ExecuteGrade) = op.m_ExecuteGrade;
	return *this;
}

std::string Form::getName() const
{
	return m_Name;
}

bool Form::getIsSigned() const
{
	return m_IsSigned;
}

int Form::getSignGrade() const
{
	return m_SignGrade;
}

int Form::getExecuteGrade() const
{
	return m_ExecuteGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (m_SignGrade < bureaucrat.getGrade())
		throw(Form::GradeTooLowException());
	m_IsSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& op)
{
	return os << op.getName() << ", is signed (" << op.getIsSigned() << "), sign grade: " << op.getSignGrade() << ", execute grade: " << op.getExecuteGrade() << std::endl;
}