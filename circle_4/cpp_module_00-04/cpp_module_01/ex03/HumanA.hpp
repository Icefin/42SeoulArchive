/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:19 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 16:57:18 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

class Weapon;

class HumanA
{
public :
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

	void attack(void);

private :
	std::string m_Name;
	Weapon&		m_Weapon;
};

#endif