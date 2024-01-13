/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:28:18 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 14:49:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
	{
		ClapTrap ct("geshin");

		ct.attack("Monster");
		ct.beRepaired(10);
		ct.takeDamage(10);
		ct.takeDamage(10);
		ct.takeDamage(10);
		ct.takeDamage(10);
		ct.takeDamage(10);
	}
	
	{
		ClapTrap ct("geshin");

		ct.attack("Monster");
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
		ct.beRepaired(10);
	}
}