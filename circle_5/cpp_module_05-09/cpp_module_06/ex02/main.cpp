/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:53:53 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 20:24:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base* generate()
{
	srand(time(NULL));
	int random = rand() % 3;
	switch (random)
	{
		case 0 : return new A();
		case 1 : return new B();
		case 2 : return new C();
	}
	return NULL;
}

//If dynamic_cast cannot cast pointer type, return NULL
void identify(Base* p)
{
	std::cout << "Pointer type identifier\n";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Actual type is A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Actual type is B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Actual type is C\n";
	else
		std::cout << "What...?\n";
}

//If dynamic_cast cannot cast reference type, throw exception 
void identify(Base& p)
{
	std::cout << "Reference type identifier\n";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Actual type is A\n";
		return;
	}
	catch(...) { }
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Actual type is B\n";
		return;
	}
	catch(...) { }
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Actual type is C\n";
		return;
	}
	catch(...) { }
	std::cout << "What...?\n";
}

int main()
{
	{
		Base* b1 = generate();
		Base* b2 = generate();
		Base* b3 = generate();
		
		identify(b1);
		identify(b2);
		identify(b3);

		delete b1;
		delete b2;
		delete b3;
	}

	{
		Base& b1 = *generate();
		Base& b2 = *generate();
		Base& b3 = *generate();
		
		identify(b1);
		identify(b2);
		identify(b3);

		delete &b1;
		delete &b2;
		delete &b3;
	}
}