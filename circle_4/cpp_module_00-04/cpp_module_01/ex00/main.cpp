/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:53:44 by geshin            #+#    #+#             */
/*   Updated: 2023/12/18 20:17:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(int argc, char** argv)
{
	Zombie zombie("Default");
	zombie.announce();
	
	randomChump("RandomChump");

	Zombie* newZomb = newZombie("New");
	newZomb->announce();
	delete newZomb;
}