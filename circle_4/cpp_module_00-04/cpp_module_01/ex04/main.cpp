/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:31:14 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/27 18:29:52 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

bool isValidArguments(int argc, char** argv)
{
	if (argc != 4)
		return false;
	return true;
}

int main(int argc, char** argv)
{
	if (isValidArguments(argc, argv) == false)
	{
		std::cout << "Invalid Input:: Arguments should be like ./replace <filename> <s1> <s2>\n";
		return 0;
	}
	
}