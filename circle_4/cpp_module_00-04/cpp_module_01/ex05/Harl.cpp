/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:32:53 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/28 10:20:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//https://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
void Harl::complain(std::string level)
{
	static const std::string flag[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*shout[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i) {
		if (flag[i] == level)
			(this->*shout[i])();
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-chesse-triple-pickle=special-ketchup burger.\n I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n You didn't put enough bacon in my burgur!\n If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable!\n I want to speak to the manager now.\n";
}