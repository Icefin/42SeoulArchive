/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:20:20 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 16:45:08 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
public :
	Cat();
	Cat(const Cat& rhs);
	virtual ~Cat();

	Cat& operator=(const Cat& rhs);

	virtual std::string getType() const;
	virtual void makeSound() const;

	void printIdeaSource() const;

private :
	Brain* m_Brain;
};

#endif