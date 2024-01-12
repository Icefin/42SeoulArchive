/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:33:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/12 18:39:46 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
public :
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& rhs);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(const std::string& type);

private :
	static const int	s_TemplateMax = 4;
	int					m_TemplateNum;
	AMateria			*m_Templates[4];
;
};

#endif