/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:08:49 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/08 01:20:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string cmd;

	while (true) {
		std::cin >> cmd;

		if (cmd == "ADD")
			phoneBook.AddContact();
		else if (cmd == "SEARCH")
			phoneBook.SearchContact();
		else if (cmd == "EXIT")
			break;
	}
}