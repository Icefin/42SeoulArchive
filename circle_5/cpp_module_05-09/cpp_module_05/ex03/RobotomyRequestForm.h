/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:45 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:21:42 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public :
	static const int s_SignGrade = 72;
	static const int s_ExecuteGrade = 46;

public :
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& op);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& op);

	virtual void execute(const Bureaucrat& executor) const;
};

#endif