/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:43:57 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 22:06:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include "easyfind.h"

int main()
{
	{
		std::array<int, 10> a = {1,2,3,4,5,6,7,8,9,10};
		std::array<int, 10>::iterator iter = easyfind(a, 8);
		std::cout << "Found Number: " << *iter << std::endl;
	}

	{
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		std::vector<int>::iterator iter = easyfind(v, 3);
		std::cout << "Found Number: " << *iter << std::endl;
	}

	{
		std::list<int> list;
		for (int i = 0; i < 10; ++i)
			list.push_back(i);
		std::list<int>::iterator iter = easyfind(list, 4);
		std::cout << "Found Number: " << *iter << std::endl;
	}

	{
		std::set<int> s;
		for (int i = 0; i < 10; ++i)
			s.insert(i);
		std::set<int>::iterator iter = easyfind(s, 7);
		std::cout << "Found Number: " << *iter << std::endl;
	}

	{
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		std::vector<int>::iterator iter = easyfind(v, 42);
		if (iter == v.end())
			std::cout << "Cannot find target\n";
	}
}