/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:04:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 17:37:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

void bureaucratTest(Bureaucrat& b)
{
	Intern intern;
	
	AForm* pf = intern.makeForm("PresidentialPardon", "PTarget");
	AForm* rf = intern.makeForm("RobotomyRequest", "STarget");
	AForm* sf = intern.makeForm("ShrubberyCreation", "RTarget");
	AForm* unknown = intern.makeForm("UnknownForm", "UTarget");

	b.signForm(*pf);
	b.signForm(*pf);
	b.signForm(*rf);
	b.signForm(*sf);

	b.executeForm(*pf);
	b.executeForm(*rf);
	b.executeForm(*sf);

	delete pf;
	delete rf;
	delete sf;
}

//void leaks()
//{
//	system("leaks test");
//}

int main()
{
	//atexit(leaks);
	try
	{
		Bureaucrat	b2("b2", 4);
		Bureaucrat	b3("b3", 42);
		Bureaucrat	b4("b4", 84);
		Bureaucrat	b5("b5", 126);

		bureaucratTest(b2);
		bureaucratTest(b3);
		bureaucratTest(b4);
		bureaucratTest(b5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}