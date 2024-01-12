/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:24:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/12 16:50:40 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter
{
public :
	Character();
	Character(const std::string& name);
	Character(const Character& rhs);
	~Character();

	Character& operator=(const Character& rhs);

	virtual const std::string& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	
private :
	static const int	s_SlotMax = 4;
	int					m_SlotIdx;;
	AMateria			*m_Inventory;
};

#endif