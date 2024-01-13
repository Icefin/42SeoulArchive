/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:12 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 14:52:17 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
	{
		ScavTrap st("geshin");

		st.attack("Monster");
		st.takeDamage(20);
		st.takeDamage(20);
		st.takeDamage(20);
		st.takeDamage(20);
		st.takeDamage(20);
		st.takeDamage(20);
	}
	
	{
		ScavTrap st("geshin");
		
		for (int i = 0; i < 50; ++i)
			st.guardGate();
		st.beRepaired(10);
	}
}