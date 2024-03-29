/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:53:44 by geshin            #+#    #+#             */
/*   Updated: 2024/01/06 13:45:02 by geshin           ###   ########.fr       */
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