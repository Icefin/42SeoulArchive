/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:48 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 15:26:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public :
	static const int s_SignGrade = 145;
	static const int s_ExecuteGrade = 137;

public :
	class FileIOException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& op);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& op);

	virtual void execute(const Bureaucrat& executor) const;
};

#endif