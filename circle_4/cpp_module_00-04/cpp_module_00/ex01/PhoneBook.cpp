/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:30 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/23 14:51:18 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_ContactSize = 0;
	m_InsertIdx = 0;
}

PhoneBook::~PhoneBook()
{
	//__noop;
}

void PhoneBook::AddContact()
{
	std::cout << "\n[[Input New Contact]]\n";
	m_Contacts[m_InsertIdx].InitContact();
	m_InsertIdx = (m_InsertIdx + 1) % 8;
	m_ContactSize = std::min(8, m_ContactSize + 1);
	std::cout << "New Contact is added to PhoneBook...\n\n";
}

void PhoneBook::SearchContact()
{
	if (m_ContactSize <= 0) {
		std::cout << "Contact list is empty...\n\n";
		return;
	}
	PrintContactsOverall();
	std::cout << std::endl;

	std::string cmd;
	while (std::cin.rdstate() == false) {
		std::cout 
			<< "If you need more info. input proper index (0 ~ " 
			<< m_ContactSize - 1 
			<< ") or exit to anyother: ";
		std::getline(std::cin, cmd);
		int idx = std::atoi(cmd.c_str());
		if (cmd.length() > 1 || cmd[0] < '0' || cmd[0] >= '9') {
			std::cout << "Finish Searching...\n";
			break;
		}
		if (idx >= 0 && idx < m_ContactSize) {
			m_Contacts[idx].PrintDetail();
			std::cout << std::endl;
		}
		else {
			std::cout << "Finish Searching...\n";
			break;
		}
	}
	std::cout << std::endl;
}

void PhoneBook::PrintContactsOverall()
{
	std::cout 
			<< "[[Print Contact Overall]]\n"
			<< "|     Index| FirstName|  LastName|  NickName|\n";
	for (int idx = 0; idx < m_ContactSize; ++idx) {
		std::cout << "|         " << idx << "|";
		m_Contacts[idx].PrintSummary();
		std::cout << std::endl;
	}
}
