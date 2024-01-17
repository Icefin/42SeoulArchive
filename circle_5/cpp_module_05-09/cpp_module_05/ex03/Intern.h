/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:06:19 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 17:17:38 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <string>

class AForm;

class Intern
{
public :
	class UnknownFormException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	Intern();
	Intern(const Intern& op);
	~Intern();
	Intern& operator=(const Intern& op);

	AForm* makeForm(const std::string& formName, const std::string& formTarget);
};

#endif