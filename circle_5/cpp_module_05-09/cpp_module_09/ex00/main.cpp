/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:38:03 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/23 16:29:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid Input, Usage: ./btc *.txt\n";
		return 1;
	}

	try
	{
		BitcoinExchange exchanger;
		
		exchanger.init();
		exchanger.exchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}	
}