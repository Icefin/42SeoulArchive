/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:51:43 by geshin            #+#    #+#             */
/*   Updated: 2023/12/28 17:25:11 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie* horde = zombieHorde(10, "Weirdo");
	std::cout << "Horde Initialization\n";
	for (int i = 0; i < 10; ++i)
		horde[i].announce();
	delete[] horde;
	std::cout << "Zombie horde has been destroyed\n";
	return 0;
}