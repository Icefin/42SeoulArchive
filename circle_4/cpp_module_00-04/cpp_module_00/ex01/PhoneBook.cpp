/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:30 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/22 12:50:04 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_size = 0;
	insert_idx = 0;
}

PhoneBook::~PhoneBook()
{
	//__noop;
}

void PhoneBook::AddContact()
{
	std::cout << std::endl;
	std::cout << "[[Input New Contact]]\n";
	m_contacts[insert_idx].InitContact();
	insert_idx = (insert_idx + 1) % 8;
	contact_size = std::min(8, contact_size + 1);
	std::cout << "New Contact is added to PhoneBook...\n\n";
}

void PhoneBook::SearchContact()
{
	if (contact_size <= 0) {
		std::cout << "Contact list is empty...\n\n";
		return;
	}
	std::cout << std::endl;
	PrintContactsOverall();
	std::cout << std::endl;

	std::string cmd;
	while (std::cin.rdstate() == false) {
		std::cout << "If you need more info. input proper index (0 ~ " << contact_size - 1 << "): ";
		std::getline(std::cin, cmd);
		//FIX THIS!!
		int idx = std::stoi(cmd);
		if (idx >= 0 && idx < contact_size) {
			m_contacts[idx].PrintDetail();
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
	std::cout << "[[Print Contact Overall]]\n";
	for (int idx = 0; idx < contact_size; ++idx) {
		std::cout << "    Index|" << "         " << idx << std::endl;
		m_contacts[idx].PrintSummary();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::Contact::InitContact()
{
	std::cout << "Input FirstName: ";
	std::getline(std::cin, firstName);
	std::cout << "Input LastName: ";
	std::getline(std::cin, lastName);
	std::cout << "Input NickName: ";
	std::getline(std::cin, nickName);
	std::cout << "Input PhoneNumber: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Input DarkestSecret: ";
	std::getline(std::cin, darkestSecret);
}

void PhoneBook::Contact::PrintSummary()
{
	std::cout << "FirstName|";
	if (firstName.length() <= 10) {
		std::cout.width(10);
		std::cout << firstName << std::endl;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << firstName[i];
		std::cout << ".\n";
	}
	std::cout << " LastName|";
	if (lastName.length() <= 10) {
		std::cout.width(10);
		std::cout << lastName << std::endl;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << lastName[i];
		std::cout << ".\n";
	}
	std::cout << " NickName|";
	if (nickName.length() <= 10) {
		std::cout.width(10);
		std::cout << nickName << std::endl;
	}
	else {
		for (size_t i = 0; i < 9; ++i)
			std::cout << nickName[i];
		std::cout << ".\n";
	}
}

void PhoneBook::Contact::PrintDetail()
{
	std::cout 
		<< "FirstName     :" << firstName << std::endl
		<< "LastName      :" << lastName << std::endl
		<< "NickName      :" << nickName << std::endl
		<< "PhoneNumber   :" << phoneNumber << std::endl
		<< "DarkestSecret :" << darkestSecret << std::endl;
}