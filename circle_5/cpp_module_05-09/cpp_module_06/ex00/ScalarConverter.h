/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:41:20 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 16:45:15 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <exception>
#include <string>

class ScalarConverter
{
public :
	class UnconvertableException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class NondisplayableException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	static void convert(const std::string& value);

private :
	ScalarConverter();
	ScalarConverter(const ScalarConverter& op);
	virtual ~ScalarConverter() = 0;
	ScalarConverter& operator=(const ScalarConverter& op);
};

#endif