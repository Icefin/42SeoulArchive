/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:36:11 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/26 18:49:12 by geshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	//__noop;
}

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