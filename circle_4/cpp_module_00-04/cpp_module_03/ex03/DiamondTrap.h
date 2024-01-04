/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:43:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 23:48:17 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.h"
# include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap
{
public :
	DiamondTrap();
	DiamondTrap(const DiamondTrap& rhs);
	virtual ~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& rhs);
	virtual void attack(const std::string &target) override;

private :
	void whoAmI();
};

#endif