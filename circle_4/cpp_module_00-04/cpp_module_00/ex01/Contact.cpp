/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:24:39 by geshin            #+#    #+#             */
/*   Updated: 2023/12/23 14:42:50 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::InitContact()
{
	std::cout << "Input FirstName: ";
	std::getline(std::cin, m_FirstName);
	std::cout << "Input LastName: ";
	std::getline(std::cin, m_LastName);
	std::cout << "Input NickName: ";
	std::getline(std::cin, m_NickName);
	std::cout << "Input PhoneNumber: ";
	std::getline(std::cin, m_PhoneNumber);
	std::cout << "Input DarkestSecret: ";
	std::getline(std::cin, m_DarkestSecret);
}

void Contact::PrintSummary()
{
	if (m_FirstName.length() <= 10) {
		std::cout.width(10);
		std::cout << m_FirstName;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << m_FirstName[i];
		std::cout << ".";
	}
	std::cout << "|";
	if (m_LastName.length() <= 10) {
		std::cout.width(10);
		std::cout << m_LastName;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << m_LastName[i];
		std::cout << ".";
	}
	std::cout << "|";
	if (m_NickName.length() <= 10) {
		std::cout.width(10);
		std::cout << m_NickName;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << m_NickName[i];
		std::cout << ".";
	}
	std::cout << "|";
}

void Contact::PrintDetail()
{
	std::cout 
		<< "FirstName     :" << m_FirstName << std::endl
		<< "LastName      :" << m_LastName << std::endl
		<< "NickName      :" << m_NickName << std::endl
		<< "PhoneNumber   :" << m_PhoneNumber << std::endl
		<< "DarkestSecret :" << m_DarkestSecret << std::endl;
}