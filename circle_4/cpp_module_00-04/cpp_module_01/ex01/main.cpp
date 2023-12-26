/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:51:43 by geshin            #+#    #+#             */
/*   Updated: 2023/12/26 19:08:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
	Zombie* horde = zombieHorde(10, "Zumbie");
	std::cout << "Horde Initialization\n";
	for (int i = 0; i < 10; ++i)
		horde[i].announce();
	delete[] horde;
	std::cout << "Destroy horde\n";
	while(true);
	return 0;
}