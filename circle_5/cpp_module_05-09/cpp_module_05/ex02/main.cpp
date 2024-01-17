/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:05:45 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 16:41:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

void bureaucratTest(Bureaucrat& b)
{
	PresidentialPardonForm pf("President");
	RobotomyRequestForm rf("Robotomy");
	ShrubberyCreationForm sf("Shrubbery");

	b.signForm(pf);
	b.signForm(pf);
	b.signForm(rf);
	b.signForm(sf);

	b.executeForm(pf);
	b.executeForm(rf);
	b.executeForm(sf);
}

int main()
{
	try
	{
		//Bureaucrat	b1("b1", 0);
		Bureaucrat	b2("b2", 4);
		Bureaucrat	b3("b3", 42);
		Bureaucrat	b4("b4", 84);
		Bureaucrat	b5("b5", 126);
		//Bureaucrat	b6("b6", 170);

		//bureaucratTest(b1);
		bureaucratTest(b2);
		bureaucratTest(b3);
		bureaucratTest(b4);
		bureaucratTest(b5);
		//bureaucratTest(b6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}