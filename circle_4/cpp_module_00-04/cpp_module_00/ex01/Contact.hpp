/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:18:11 by geshin            #+#    #+#             */
/*   Updated: 2023/12/23 14:24:03 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
public :
	void	InitContact();
	void	PrintSummary();
	void	PrintDetail();

private :
	std::string	m_FirstName;
	std::string	m_LastName;
	std::string m_NickName;
	std::string m_PhoneNumber;
	std::string m_DarkestSecret;
};

#endif