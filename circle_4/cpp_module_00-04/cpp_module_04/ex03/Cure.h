/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:23:34 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/12 16:37:14 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
public :
	Cure();
	Cure(const Cure& rhs);
	virtual ~Cure();

	Cure& operator=(const Cure& rhs);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif