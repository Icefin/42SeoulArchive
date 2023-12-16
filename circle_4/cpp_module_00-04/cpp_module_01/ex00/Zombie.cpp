/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:11 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/16 15:43:21 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
	: m_Name(name)
{

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