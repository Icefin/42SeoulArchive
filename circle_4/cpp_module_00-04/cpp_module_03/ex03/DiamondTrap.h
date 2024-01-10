/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:43:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:06:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.h"
# include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
public :
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& rhs);
	virtual ~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& rhs);
	virtual void attack(const std::string& target);

	void whoAmI();

protected :
	virtual bool isAlive();

private :
	std::string m_Name;
};

#endif