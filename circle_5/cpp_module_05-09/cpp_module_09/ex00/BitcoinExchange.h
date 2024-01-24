/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:38:20 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/24 16:29:36 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <exception>
#include <map>

class BitcoinExchange
{
public :
	class FileIOException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class InvalidFormatException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class NonPositiveNumberException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class TooLargeNumberException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& op);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& op);

	void init();
	void exchange(const std::string& input);

private :
	float getExchangeRatio(const std::string& date) const;

	bool isValidLineFormatDB(const std::string& line) const;
	bool isValidLineFormatInput(const std::string& line) const;

private :
	std::map<std::string, float> m_Data;
};

#endif