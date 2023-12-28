/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:11 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 17:12:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: m_Name(name)
{
	//__noop;
}

Zombie::~Zombie()
{
	std::cout
		<< m_Name
		<< ": has been destroyed\n";
}

void Zombie::announce()
{
	std::cout
		<< m_Name
		<< ": BraiiiiiiinnnzzzZ...\n";
}