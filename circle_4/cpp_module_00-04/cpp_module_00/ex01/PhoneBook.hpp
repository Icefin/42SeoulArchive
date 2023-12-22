/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:33 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/22 12:46:42 by geshin           ###   ########.fr       */
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
		void	InitContact();
		void	PrintSummary();
		void	PrintDetail();
	
	private :
		std::string	firstName;
		std::string	lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	};
	
	void		PrintContactsOverall();

	Contact m_contacts[8];
	int		contact_size;
	int		insert_idx;
};

#endif