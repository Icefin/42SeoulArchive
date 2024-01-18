/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:41:18 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/18 18:28:00 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.h"

const char* ScalarConverter::UnconvertableException::what() const throw()
{
	return "impossible";
}

const char* ScalarConverter::NondisplayableException::what() const throw()
{
	return "Non displayable";
}

void ScalarConverter::convert(const std::string& value)
{
	char* eptr;
	double dvalue = std::strtod(value.c_str(), &eptr);
	bool isNaN = false;
	if (value == "inf" || value == "inff")
		dvalue = INFINITY;
	else if (value == "-inf" || value == "-inff")
		dvalue = -INFINITY;
	else if (value == "nan" || value == "nanf") {
		dvalue = NAN;
		isNaN = true;
	}

	try
	{
		if (isNaN == true || dvalue == INFINITY || dvalue == -INFINITY || dvalue < INT8_MIN || dvalue > INT8_MAX)
			throw(ScalarConverter::UnconvertableException());
		if (value.back() != 'f' && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		if (isprint(static_cast<int>(dvalue)) == false)
			throw(ScalarConverter::NondisplayableException());
		std::cout << "char: " << static_cast<char>(dvalue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}

	try
	{
		if (isNaN == true || dvalue > INT32_MAX || dvalue < INT32_MIN)
			throw(ScalarConverter::UnconvertableException());
		if (dvalue == 0 && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		if (value.back() != 'f' && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: " << e.what() << std::endl;
	}	

	try
	{
		if (dvalue == 0 && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		if (value.back() != 'f' && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "float: " << static_cast<float>(dvalue) << "f\n";
		std::cout.unsetf(std::ios::fixed);
	}
	catch(const std::exception& e)
	{
		std::cerr << "float: " << e.what() << std::endl;
	}	

	try
	{
		if (dvalue == 0 && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		if (value.back() != 'f' && *eptr != '\0')
			throw(ScalarConverter::UnconvertableException());
		std::cout << std::fixed;
		std::cout.precision(1);
		std::cout << "double: " << dvalue << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: " << e.what() << std::endl;
	}	
}

ScalarConverter::ScalarConverter()
{
	//__noop;
}

ScalarConverter::ScalarConverter(const ScalarConverter& op)
{
	(void)op;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& op)
{
	(void)op;
	return *this;
}