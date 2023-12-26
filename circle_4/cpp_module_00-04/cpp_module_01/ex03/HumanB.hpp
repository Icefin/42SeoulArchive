/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:39 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/26 20:23:23 by singeonho        ###   ########.fr       */
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

	void attack();
	void setWeapon(Weapon weapon);
private :
	std::string m_Name;
	Weapon		m_Weapon;
};

#endif