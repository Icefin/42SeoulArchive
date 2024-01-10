/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:20:15 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/10 16:55:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

class WrongAnimal
{
public :
	WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& rhs);

	std::string getType() const;
	void makeSound() const;

protected :
	std::string m_Type;
};

#endif