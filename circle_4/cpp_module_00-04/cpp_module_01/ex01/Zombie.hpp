/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:50:27 by geshin            #+#    #+#             */
/*   Updated: 2023/12/28 17:17:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
public :
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);

private :
	std::string m_Name;
};

Zombie* zombieHorde(int N, std::string name);

#endif