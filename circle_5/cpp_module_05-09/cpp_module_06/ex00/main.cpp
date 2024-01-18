/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:40:47 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 17:39:30 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <value>\n";
        return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}