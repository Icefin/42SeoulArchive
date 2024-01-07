/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:03 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/07 22:01:51 by singeonho        ###   ########.fr       */
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
		
		Fixed a(1.0f);
		std::cout << "a: " << a << std::endl;
		++(++a);
		std::cout << "da: " << a << std::endl;

		Fixed b(3.0f);
		std::cout << "b: " << b << std::endl;
		(b++)++;
		std::cout << "db: " << b << std::endl;
	}

	return 0;
}