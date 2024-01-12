/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:23:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/12 16:37:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.h"

class Ice : public AMateria
{
public :
	Ice();
	Ice(const Ice& rhs);
	virtual ~Ice();

	Ice& operator=(const Ice& rhs);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif