/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:08:55 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 15:35:10 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
public :
	static const int s_MaxGrade = 1;
	static const int s_MinGrade = 150;

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

	class SignedFormException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class UnsignedFormException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	AForm();
	AForm(const std::string& name, const int signGrade, const int executeGrade);
	AForm(const std::string& name, const std::string& target, const int signGrade, const int executeGrade);
	AForm(const AForm& op);
	virtual ~AForm();
	AForm& operator=(const AForm& op);

	std::string getName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void checkSignable(const Bureaucrat& bureaucrat) const;
	void beSigned(const Bureaucrat& bureaucrat);

	void checkExecutable(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;

private :
	const std::string	m_Name;
	std::string			m_Target;
	bool				m_IsSigned;
	const int			m_SignGrade;
	const int			m_ExecuteGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& op);

#endif