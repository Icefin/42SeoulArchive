/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geshin <geshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:51:02 by geshin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/29 12:26:11 by geshin           ###   ########.fr       */
=======
/*   Updated: 2023/12/28 17:16:47 by singeonho        ###   ########.fr       */
>>>>>>> 6d6f01be5136305beb8a37676761a8a94ae34da1
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>


Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i] = Zombie(name);
		std::cout << i <<": Zombie Initialized\n";
	}
	return horde;
}