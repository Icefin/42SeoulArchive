/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:20:13 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:54:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public :
	WrongCat();
	WrongCat(const WrongCat& rhs);
	~WrongCat();

	WrongCat& operator=(const WrongCat& rhs);

	std::string getType() const;
	void makeSound() const;
};

#endif