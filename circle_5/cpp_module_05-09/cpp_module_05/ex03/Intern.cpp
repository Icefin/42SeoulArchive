/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:06:17 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 17:36:03 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

const char* Intern::UnknownFormException::what() const throw()
{
	return "UnknownForm";
}

Intern::Intern()
{
	//__noop;
}

Intern::Intern(const Intern& op)
{
	(void)op;
}

Intern::~Intern()
{
	//__noop;
}

Intern& Intern::operator=(const Intern& op)
{
	(void)op;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	static const std::string formNameList[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	try
	{
		int idx;
		for (idx = 0; idx < 3; ++idx) {
			if (formName == formNameList[idx])
				break;
		}
		switch (idx)
		{
		case 0 : return new PresidentialPardonForm(formTarget);
		case 1 : return new RobotomyRequestForm(formTarget);
		case 2 : return new ShrubberyCreationForm(formTarget);
		default : throw(UnknownFormException());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}