/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:16:43 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:43:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal
{
public :
	Animal();
	Animal(const Animal& rhs);
	virtual ~Animal();

	Animal& operator=(const Animal& rhs);

	virtual std::string getType() const;
	virtual void makeSound() const;

protected :
	std::string m_Type;
};

#endif