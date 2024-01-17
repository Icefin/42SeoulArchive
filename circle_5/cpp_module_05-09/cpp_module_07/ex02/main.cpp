/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:12:49 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 21:41:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.h"

int main()
{
	{
		Array<int> a;
		std::cout << a.size() << std::endl;
		std::cout << "\n\n";
	}

	{
		Array<int> a(5);
		std::cout << a.size() << std::endl;
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = i * i;
		for (unsigned int i = 0; i < a.size(); ++i)
			std::cout << a[i] << ", ";
		std::cout << "\n\n";
	}

	{
		Array<char> a(10);
		std::cout << a.size() << std::endl;
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = 'a' + i;
		for (unsigned int i = 0; i < a.size(); ++i)
			std::cout << a[i] << ", ";
		std::cout << "\n\n";
	}

	{
		Array<std::string> a(4);
		a[0] = "Hello";
		a[1] = "World";
		a[2] = "Welcome";
		a[3] = "Cpp";
		for (unsigned int i = 0; i < a.size(); ++i)
			std::cout << a[i] << ", ";
		std::cout << "\n\n";
	}

	{
		Array<int> a(42);
		try
		{
			int test = a[42];
			std::cout << "Test: " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		Array<double> a(42);
		try
		{
			double test = a[-1];
			std::cout << "Test: " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}