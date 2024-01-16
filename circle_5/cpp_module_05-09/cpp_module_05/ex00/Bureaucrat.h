/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:54:11 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/16 22:57:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
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
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& op);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& op);
	
	std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

private :
	const std::string 	m_Name;
	int					m_Grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& op);

#endif
