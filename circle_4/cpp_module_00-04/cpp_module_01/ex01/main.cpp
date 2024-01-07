/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:51:43 by geshin            #+#    #+#             */
/*   Updated: 2024/01/06 13:46:51 by geshin           ###   ########.fr       */
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