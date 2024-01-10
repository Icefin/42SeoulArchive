/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:07 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 15:24:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap
{
public :
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& rhs);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& rhs);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected :
	virtual bool isAlive();

protected :
	std::string m_Name;
	int			m_HitPoint;
	int			m_EnergyPoint;
	int			m_AttackDamage;
};

#endif