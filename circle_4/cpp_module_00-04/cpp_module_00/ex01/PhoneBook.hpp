/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:33 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/15 16:41:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>

class PhoneBook
{
public :
				PhoneBook();
				~PhoneBook();

		void	AddContact();
		void	SearchContact();

private :
	class Contact
	{
	public :
		std::string	firstName;
		std::string	lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

		void	PrintContact(int idx);
	};

	Contact m_contacts[8];
	int		m_front;
	int		m_end;
};

#endif