/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:53:44 by geshin            #+#    #+#             */
/*   Updated: 2023/12/17 17:23:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

extern Zombie* newZombie(std::string name);
extern void randomChump(std::string name);

int main(int argc, char** argv)
{
	Zombie zombie("Default");
	zombie.announce();
	
	randomChump("RandomChump");

	Zombie* newZomb = newZombie("New");
	newZomb->announce();
	delete newZomb;
}