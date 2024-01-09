/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:03 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/09 13:36:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	
	{
		float f = 1.0f;
		++(++f);
		std::cout << "f: " << f << std::endl;
		
		Fixed a1;
		(++a1);
		std::cout << "a1: " << a1 << std::endl;

		Fixed a2;
		(++(++a2));
		std::cout << "a2: " << a2 << std::endl;

		Fixed a3;
		++(++(++a3));
		std::cout << "a3: " << a3 << std::endl;

		Fixed b1;
		(b1++);
		std::cout << "b1: " << b1 << std::endl;

		Fixed b2;
		(b2++)++;
		std::cout << "b2: " << b2 << std::endl;

		Fixed b3;
		((b3++)++)++;
		std::cout << "b3: " << b3 << std::endl;
	}
	return 0;
}