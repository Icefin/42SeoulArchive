/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:43 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 17:02:16 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "None", RobotomyRequestForm::s_SignGrade, RobotomyRequestForm::s_ExecuteGrade)
{
	//__noop;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, RobotomyRequestForm::s_SignGrade, RobotomyRequestForm::s_ExecuteGrade)
{
	//__noop;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& op)
	: AForm(op)
{
	//__noop;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//__noop;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& op)
{
	AForm::operator=(op);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);
	std::cout << "* some drilling noises... *\n";

	int* rand = new int;
	int isSuccess = (unsigned long)(&rand) % 10000;
	if (isSuccess < 5000)
		std::cout << this->getTarget() << " has been robotomized successfully\n";
	else
		std::cout << this->getTarget() << " has not been robotomized\n";
	delete rand;
}