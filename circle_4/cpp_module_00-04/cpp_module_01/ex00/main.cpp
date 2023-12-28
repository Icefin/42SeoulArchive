/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:53:44 by geshin            #+#    #+#             */
/*   Updated: 2023/12/28 17:10:56 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("Default");
	zombie.announce();
	
	randomChump("RandomChump");

	Zombie* newZomb = newZombie("New");
	newZomb->announce();
	delete newZomb;
}