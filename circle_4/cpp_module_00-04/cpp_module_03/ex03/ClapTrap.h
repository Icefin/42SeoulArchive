/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:43:23 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 23:43:25 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public :
	ClapTrap();
	ClapTrap(const ClapTrap& rhs);
	virtual ~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected :
	std::string m_Name;
	int			m_HitPoint;
	int			m_EnergyPoint;
	int			m_AttackDamage;
};

#endif