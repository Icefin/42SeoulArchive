/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:28:18 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:11:31 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
	ClapTrap ct("geshin");

	std::string targetName = "target";

	ct.attack(targetName);
	ct.beRepaired(10);
	ct.takeDamage(10);
}