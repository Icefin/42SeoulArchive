/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:33:36 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/13 17:58:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.h"

#define MATERIA_SIZE 4

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
	int					m_TemplateNum;
	AMateria			*m_Templates[MATERIA_SIZE];
};

#endif