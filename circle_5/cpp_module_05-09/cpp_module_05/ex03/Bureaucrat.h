/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:54:11 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 14:58:07 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
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

public :
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& op);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& op);
	
	std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	void signForm(AForm& form) const;

	void executeForm(const AForm& form);

private :
	const std::string 	m_Name;
	int					m_Grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& op);

#endif
