/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:41 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:21:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public :
	static const int s_SignGrade = 25;
	static const int s_ExecuteGrade = 5;

public :
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& op);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& op);

	virtual void execute(const Bureaucrat& executor) const;
};

#endif