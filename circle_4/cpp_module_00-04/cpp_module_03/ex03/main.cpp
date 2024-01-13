/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:02:38 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 15:10:24 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

int main()
{
	{
		DiamondTrap dt("geshin");

		dt.attack("Monster");
		dt.takeDamage(20);
		dt.takeDamage(20);
		dt.takeDamage(20);
		dt.takeDamage(20);
		dt.takeDamage(20);
		dt.takeDamage(20);
	}

	{
		DiamondTrap dt("geshin");

		for (int i = 0; i < 60; ++i)
			dt.whoAmI();
	}

	{
		DiamondTrap dt("geshin");
		DiamondTrap op("other");

		op.takeDamage(80);
		dt.takeDamage(60);
		op = dt;
		op.takeDamage(10);
		op.takeDamage(10);
		op.takeDamage(10);
		op.takeDamage(10);
		op.takeDamage(10);
		op.takeDamage(10);
	}
}
