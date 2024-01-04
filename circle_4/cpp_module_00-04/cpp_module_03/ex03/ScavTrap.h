/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:43:10 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 23:43:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap();
	ScavTrap(const ScavTrap& rhs);
	virtual ~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	virtual void attack(const std::string& target) override;

private :
	void guardGate();
};

#endif