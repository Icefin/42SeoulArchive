/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:14:49 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:05:58 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"

void leaks()
{
	system("leaks test");
}

int main()
{
	atexit(leaks);
	{
		Animal* animals[10];

		for (int i = 0; i < 5; ++i) {
			animals[i] = new Dog();
			animals[i + 5] = new Cat();
		}
			
		for (int i = 0; i < 10; ++i)
			delete animals[i];
	}

	{
		Cat* c1 = new Cat();
		Cat* c2 = new Cat();

		c1->printIdeaSource();
		c2->printIdeaSource();

		*c1 = *c2;
		c1->printIdeaSource();
		c2->printIdeaSource();

		delete c1;
		delete c2;
	}

	{
		Dog* d1 = new Dog();
		Dog* d2 = new Dog();

		d1->printIdeaSource();
		d2->printIdeaSource();

		*d1 = *d2;
		d1->printIdeaSource();
		d2->printIdeaSource();

		delete d1;
		delete d2;
	}
}