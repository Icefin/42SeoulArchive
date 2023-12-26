/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:09:33 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/23 14:24:46 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public :
				PhoneBook();
				~PhoneBook();

		void	AddContact();
		void	SearchContact();

private :

	
	void		PrintContactsOverall();

	Contact m_Contacts[8];
	int		m_ContactSize;
	int		m_InsertIdx;
};

#endif