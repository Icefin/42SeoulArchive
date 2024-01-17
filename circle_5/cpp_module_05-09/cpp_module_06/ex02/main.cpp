/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:53:53 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 18:01:26 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void identify(Base* p)
{
	
}

void identify(Base& p)
{
	
}

int main()
{
	
}