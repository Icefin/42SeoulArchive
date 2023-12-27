/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:57:06 by singeonho         #+#    #+#             */
/*   Updated: 2023/12/27 16:53:06 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//https://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
void Harl::complain(std::string level)
{
	static const std::string flag[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*shout[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int idx;
	for (idx = 0; idx < 4; ++idx) 
	{
		if (flag[idx] == level)
			break;
	}
	switch (idx)
	{
		case 0 :
			(this->*shout[0])();
			break;
		case 1 :
			(this->*shout[0])();
			(this->*shout[1])();
			break;
		case 2 :
			(this->*shout[0])();
			(this->*shout[1])();
			(this->*shout[2])();
			break;
		case 3 :
			(this->*shout[0])();
			(this->*shout[1])();
			(this->*shout[2])();
			(this->*shout[3])();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void Harl::debug(void)
{
	std::cout 
		<< "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-chesse-triple-pickle=special-ketchup burger.\n I really do!\n";
}

void Harl::info(void)
{
	std::cout 
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n You didn't put enough bacon in my burgur!\n If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable!\n I want to speak to the manager now.\n";
}