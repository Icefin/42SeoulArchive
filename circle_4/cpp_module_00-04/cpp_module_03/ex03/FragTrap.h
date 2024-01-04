/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:43:30 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/04 23:43:35 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap : public ClapTrap
{
public :
	FragTrap();
	FragTrap(const FragTrap& rhs);
	virtual ~FragTrap();

	FragTrap& operator=(const FragTrap& rhs);

private :
	void highFivesGuys();
};

#endif