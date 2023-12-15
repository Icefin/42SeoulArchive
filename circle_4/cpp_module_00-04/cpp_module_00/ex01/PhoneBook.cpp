/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:30 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/15 17:09:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_front = 0;
	m_end = 0;
}

PhoneBook::~PhoneBook()
{
	//__noop;
}

void PhoneBook::AddContact()
{
	Contact contact;
	int next = (m_end + 1) % 8;

	if (next == m_front)
		m_front = (m_front + 1) % 8;
	
	std::cout << "Input FirstName: ";
	std::cin >> contact.firstName;
	std::cout << "Input LastName: ";
	std::cin >> contact.lastName;
	std::cout << "Input NickName: ";
	std::cin >> contact.nickName;
	std::cout << "Input PhoneNumber: ";
	std::cin >> contact.phoneNumber;
	std::cout << "Input DarkestSecret: ";
	std::cin >> contact.darkestSecret;

	m_contacts[m_end] = contact;
	m_end = next;
	std::cout << "New Contact is Added to PhoneBook\n\n";
}

void PhoneBook::SearchContact()
{
	if (m_front < m_end)
	{
		for (int idx = m_front; idx < m_end; ++idx)
			m_contacts[idx].PrintContact(idx);
	}
	else if (m_front == m_end)
		m_contacts[m_front].PrintContact(m_front);
	else
	{
		for (int idx = m_front; idx < 8; ++idx)
			m_contacts[idx].PrintContact(idx);
		for (int idx = 0; idx < m_end; ++idx)
			m_contacts[idx].PrintContact(idx);
	}
	std::cout << std::endl;
}

void PhoneBook::Contact::PrintContact(int idx)
{
	std::cout 
		<< "Index: " << idx << std::endl
		<< "FirstName: " << firstName << std::endl
		<< "LastName: " << lastName << std::endl
		<< "NickName: " << nickName << std::endl
		<< std::endl;
}