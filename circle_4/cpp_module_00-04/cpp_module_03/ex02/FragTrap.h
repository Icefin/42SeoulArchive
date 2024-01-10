/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:39:25 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:08:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public :
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& rhs);
	virtual ~FragTrap();

	FragTrap& operator=(const FragTrap& rhs);

	virtual void attack(const std::string& target);
	void highFivesGuys();

protected :
	virtual bool isAlive();
};

#endif