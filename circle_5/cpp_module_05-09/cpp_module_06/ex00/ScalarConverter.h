/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:41:20 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/17 20:27:22 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>

class ScalarConverter
{
public :
	static void convert(const std::string& value);

private :
	ScalarConverter();
	ScalarConverter(const ScalarConverter& op);
	virtual ~ScalarConverter() = 0;
	ScalarConverter& operator=(const ScalarConverter& op);
};

#endif