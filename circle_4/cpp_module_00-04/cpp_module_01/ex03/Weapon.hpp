/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:13:59 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 17:40:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
public :
						Weapon(std::string type);
						~Weapon(void);

	const std::string&	getType(void) const;
	void				setType(std::string type);

private :
	std::string		m_Type;
};

#endif