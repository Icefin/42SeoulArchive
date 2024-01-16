/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:13:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/16 23:22:47 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Form
{
public :
	class GradeTooHighException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	Form();
	Form(const Form& op);
	~Form();
	Form& operator=(const Form& op);

	void beSigned(Bureaucrat& bureaucrat);

private :
	const std::string	m_Name;
	bool				m_IsSigned;
	const int			m_SignGrade;
	const int			m_ExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& op);

#endif