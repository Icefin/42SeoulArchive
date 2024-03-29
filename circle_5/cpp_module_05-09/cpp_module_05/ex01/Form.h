/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:13:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:37:05 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <exception>
#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

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
	Form(const std::string& name, const int signGrade, const int executeGrade);
	Form(const Form& op);
	~Form();
	Form& operator=(const Form& op);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);

private :
	const std::string	m_Name;
	bool				m_IsSigned;
	const int			m_SignGrade;
	const int			m_ExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& op);

#endif