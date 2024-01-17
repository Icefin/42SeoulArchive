/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:22 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 16:29:44 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "None", PresidentialPardonForm::s_SignGrade, PresidentialPardonForm::s_ExecuteGrade)
{
	//__noop;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", target, PresidentialPardonForm::s_SignGrade, PresidentialPardonForm::s_ExecuteGrade)
{
	//__noop;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& op)
	: AForm(op)
{
	//__noop;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//__noop;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& op)
{
	AForm::operator=(op);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}