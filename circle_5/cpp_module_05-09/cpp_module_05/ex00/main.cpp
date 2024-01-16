/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:00:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/16 23:11:39 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat b1("geshin", 42);
		Bureaucrat b2("jihweon", 84);
		Bureaucrat b3("jinhy", 126);

		std::cout << "Text Fin\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b1("geshin", 4242);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b1("geshin", 0);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("geshin", 142);
		for (int i = 0; i < 10; ++i) {
			b1.decreaseGrade();
			std::cout << b1.getName() << ": " << b1.getGrade() << std::endl; 
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("geshin", 2);
		for (int i = 0; i < 10; --i) {
			b1.increaseGrade();
			std::cout << b1.getName() << ": " << b1.getGrade() << std::endl; 
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}