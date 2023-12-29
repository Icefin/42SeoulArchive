/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:51:32 by geshin            #+#    #+#             */
/*   Updated: 2023/12/28 17:18:08 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default constructor called\n";
}

Zombie::Zombie(std::string name)
	: m_Name(name)
{
	std::cout << "Naming constructor called\n";
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