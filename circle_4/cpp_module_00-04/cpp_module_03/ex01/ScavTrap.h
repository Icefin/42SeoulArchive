/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:16 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:08:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& rhs);
	virtual ~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	virtual void attack(const std::string& target);

	void guardGate();

protected :
	virtual bool isAlive();
};

#endif