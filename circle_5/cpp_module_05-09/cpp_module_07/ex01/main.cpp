/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:56:31 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 21:11:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.h"

void test_integer(int& n)
{
	++n;
}

void test_float(float& f)
{
	++f;
}

void test_char(char& c)
{
	c = toupper(c);
}

void test_string(std::string& str)
{
	for (int i = 0; i < str.length(); ++i)
		str[i] = toupper(str[i]);
}

int main()
{
	{
		int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, test_integer);
		for (int i = 0; i < 5; ++i)
			std::cout << arr[i] << ", ";
		std::cout << "\n\n";
	}

	{
		float arr[] = {2.1, 3.2, 4.3, 5.4, 6.5};
		iter(arr, 5, test_float);
		for (int i = 0; i < 5; ++i)
			std::cout << arr[i] << ", ";
		std::cout << "\n\n";
	}

	{
		char arr[] = {'a', 'e', 'i', 'o', 'u'};
		iter(arr, 5, test_char);
		for (int i = 0; i < 5; ++i)
			std::cout << arr[i] << ", ";
		std::cout << "\n\n";
	}

	{
		std::string arr[] = {"Hello", "World", "Welcome", "To", "cpp"};
		iter(arr, 5, test_string);
		for (int i = 0; i < 5; ++i)
			std::cout << arr[i] << ", ";
		std::cout << "\n\n";
	}
}