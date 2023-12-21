/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:08:49 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/21 16:27:33 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string cmd;

	while (std::cin.rdstate() == false) {
		std::cout << "Valid commands: ADD, SEARCH, EXIT\n";
		std::cout << "Input: ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD")
			phoneBook.AddContact();
		else if (cmd == "SEARCH")
			phoneBook.SearchContact();
		else if (cmd == "EXIT") {
			std::cout << "[[Exit Program]]\n";
			break;
		}
		else
			std::cout << "Invalid Command Input\n\n";
	}
	std::cout << std::endl;
	return 0;
}