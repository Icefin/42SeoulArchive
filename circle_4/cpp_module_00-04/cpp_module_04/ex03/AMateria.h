/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:41:04 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:54:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include "ICharacter.h"

class AMateria
{
public :
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& rhs);
	virtual ~AMateria();

	const std::string& getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	AMateria& operator=(const AMateria& rhs);

protected :
	std::string m_Type;
};

#endif