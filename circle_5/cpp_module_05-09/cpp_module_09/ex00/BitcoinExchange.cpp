/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:10:59 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/24 16:34:45 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"

#include <fstream>
#include <iostream>

const char* BitcoinExchange::FileIOException::what() const throw()
{
	
}

const char* BitcoinExchange::InvalidFormatException::what() const throw()
{
	
}

const char* BitcoinExchange::NonPositiveNumberException::what() const throw()
{
	
}

const char* BitcoinExchange::TooLargeNumberException::what() const throw()
{
	
}

BitcoinExchange::BitcoinExchange()
{
	//__noop;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& op)
{
	*this = op;
}

BitcoinExchange::~BitcoinExchange()
{
	//__noop;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& op)
{
	(void)op;
	return *this;
}

void BitcoinExchange::init()
{
	std::fstream dataFile;
	dataFile.open("./data.csv");
	if (dataFile.good() == false)
		throw(BitcoinExchange::FileIOException());

	int lineNum = 0;
	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		try
		{
			if (isValidLineFormatDB(line) == false)
				throw(BitcoinExchange::InvalidFormatException());

			size_t sep = line.find(',');
			std::string date = line.substr(0, sep);
			std::string ratio = line.substr(sep + 1);
			m_Data[date] = atof(ratio.c_str());
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: line(" << lineNum << ") " << e.what() << '\n';
		}
		lineNum++;
	}
}

void BitcoinExchange::exchange(const std::string& input)
{
	std::fstream order;
	order.open(input);
	if (order.good() == false)
		throw(BitcoinExchange::FileIOException());
	
	int lineNum = 0;
	std::string line;
	std::getline(order, line);
	while (std::getline(order, line))
	{
		try
		{
			if (isValidLineFormatInput(line) == false)
				throw(BitcoinExchange::InvalidFormatException());
	
			size_t sep = line.find('|');
			std::string date = line.substr(0, sep - 1);
			float value = atof(line.substr(sep + 2).c_str());
			//TODO: Check valid value
			float ratio = getExchangeRatio(date);

			std::cout << date << "=> " << value << " = " << value * ratio << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: line(" << lineNum << ") " << e.what() << std::endl;
		}
		lineNum++;
	}
}

float BitcoinExchange::getExchangeRatio(const std::string& date) const
{
	std::map<std::string, float>::const_iterator iter = m_Data.find(date);
	if (iter != m_Data.end())
		return iter->second;

	std::map<std::string, float>::const_iterator lbound = m_Data.lower_bound(date);
	std::map<std::string, float>::const_iterator ubound = m_Data.upper_bound(date);
	
}

bool BitcoinExchange::isValidLineFormatDB(const std::string& line) const
{

}

bool BitcoinExchange::isValidLineFormatInput(const std::string& line) const
{
	
}