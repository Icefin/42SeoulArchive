/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:52:24 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 20:40:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.h"

int main()
{
	Data data;
	data.Position = 0;
	data.Rotation = 180;
	data.Name = 'c';
	data.IsAlive = true;

	Data* dptr = &data;
	uintptr_t serial = Serializer::serialize(dptr);
	Data* deserial = Serializer::deserialize(serial);

	std::cout << "Data Position: "<< deserial->Position << std::endl;
	std::cout << "Data Rotation: "<< deserial->Rotation << std::endl;
	std::cout << "Data Name: "<< deserial->Name << std::endl;
	std::cout << "Data IsAlive: "<< deserial->IsAlive << std::endl;
}