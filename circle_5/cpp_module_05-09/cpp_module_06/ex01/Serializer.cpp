/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:52:37 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 20:35:48 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer()
{
	//__noop;
}

Serializer::Serializer(const Serializer& op)
{
	(void)op;
}

Serializer::~Serializer()
{
	//__noop;
}

Serializer& Serializer::operator=(const Serializer& op)
{
	(void)op;
	return *this;
}