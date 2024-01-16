/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:13:02 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/16 23:29:23 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHigh Exception";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLow Exception";
}

Form::Form()
	: m_Name("Default"), m_IsSigned(false), m_SignGrade(0), m_ExecuteGrade(0)
{
	//__noop;
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

}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	
}

std::ostream& operator<<(std::ostream& os, const Form& op)
{
	
}