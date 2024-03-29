/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:52:32 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 20:38:32 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <cstdint>

struct Data
{
public :
	int Position;
	int Rotation;
	char Name;
	bool IsAlive;
};

class Serializer
{
public :
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private :
	Serializer();
	Serializer(const Serializer& op);
	~Serializer();
	Serializer& operator=(const Serializer& op);
};

#endif