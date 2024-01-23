/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:07:43 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/23 15:42:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include "Span.h"

int main()
{
	{
		std::cout << "Test #1\n";
		Span sp = Span(5);

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\n";
	}
	
	{
		std::cout << "Test #2\n";
		Span				sp(20);
		std::vector<int> 	v;
		srand(time(NULL));

		for (std::size_t i = 0; i < 20; ++i)
			v.push_back(rand() % 100);
		
		try
		{
			sp.addNumber(v.begin(), v.end());

			std::cout << "Span: \n";
			for (int i = 0; i < sp.size(); ++i) {
				std::cout << sp[i] << ", ";
			}
			std::cout << std::endl;
			std::cout << "Vector: \n";
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); ++i) {
				std::cout << v[i] << ", ";
			}
			std::cout << "\n\n";

			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\n";
	}

	{
		std::cout << "Test #3\n";
		Span			sp(20);
		std::set<int>	s;
		srand(time(NULL));

		for (std::size_t i = 0; i < 20; ++i)
			s.insert(rand() % 100);

		try
		{
			sp.addNumber(s.begin(), s.end());

			std::cout << "Span: \n";
			for (int i = 0; i < sp.size(); ++i) {
				std::cout << sp[i] << ", ";
			}
			std::cout << std::endl;
			std::cout << "Set: \n";
			for (int num : s) 
			{
				std::cout << num << ", ";	
			}
			std::cout << "\n\n";

			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}