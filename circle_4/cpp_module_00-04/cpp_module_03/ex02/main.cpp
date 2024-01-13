/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:03:00 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 14:54:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int main()
{
	{
		FragTrap ft("geshin");

		ft.attack("Monster");
		ft.takeDamage(20);
		ft.takeDamage(20);
		ft.takeDamage(20);
		ft.takeDamage(20);
		ft.takeDamage(20);
		ft.takeDamage(20);
	}
	
	{
		FragTrap ft("geshin");

		for (int i = 0; i < 100; ++i)
			ft.highFivesGuys();
		ft.beRepaired(10);
	}
}