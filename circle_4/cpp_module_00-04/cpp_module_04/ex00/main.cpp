/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:21:10 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:46:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		dog->makeSound();
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();

		std::cout << meta->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		meta->makeSound();
		cat->makeSound();

		delete meta;
		delete cat;
	}
}