/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:33 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/08 01:39:12 by singeonho        ###   ########.fr       */
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
	struct Contact
	{
		std::string	firstName;
		std::string	lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	};

	Contact contacts[8];
	int		idx;
};

#endif