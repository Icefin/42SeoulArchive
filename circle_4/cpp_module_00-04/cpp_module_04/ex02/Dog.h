/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:20:38 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:11:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.h"

class Dog : public Animal
{
public :
	Dog();
	Dog(const Dog& rhs);
	virtual ~Dog();

	Dog& operator=(const Dog& rhs);

	virtual std::string getType() const;
	virtual void makeSound() const;
};

#endif