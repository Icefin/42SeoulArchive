/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:32:12 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:10:09 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
	ScavTrap st("geshin");

	std::string targetName = "target";
	st.attack(targetName);
	st.guardGate();
}