/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:39 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 17:43:54 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>

class Weapon;

class HumanB
{
public :
		HumanB(std::string name);
		~HumanB(void);

	void attack(void);
	void setWeapon(Weapon& weapon);

private :
	std::string m_Name;
	Weapon*		m_Weapon;
};

#endif