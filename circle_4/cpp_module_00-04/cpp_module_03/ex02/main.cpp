/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:03:00 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:09:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int main()
{
	FragTrap ft("geshin");

	std::string targetName = "target";
	ft.attack(targetName);
	ft.highFivesGuys();
}