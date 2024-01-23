/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:04 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/23 15:42:19 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

const char* Span::OutOfRangeException::what() const throw()
{
	return "OutOfRange";
}

const char* Span::TooFewElementException::what() const throw()
{
	return "TooFewElement";
}

Span::Span()
{
	m_Data.reserve(0);
}

Span::Span(unsigned int N)
{
	m_Data.reserve(N);
}

Span::Span(const Span& op)
{
	*this = op;
}

Span::~Span()
{
	//__noop;
}

unsigned int Span::size() const
{
	return m_Data.size();
}

unsigned int Span::shortestSpan() const
{
	if (m_Data.size() < 2)
		throw(TooFewElementException());
	
	int shortest = INT32_MAX;
	for (int i = 0; i < m_Data.size() - 1; ++i) 
		shortest = m_Data[i + 1] - m_Data[i] < shortest ? m_Data[i + 1] - m_Data[i] : shortest;
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (m_Data.size() < 2)
		throw(TooFewElementException());
	
	return m_Data.back() - m_Data.front();
}

void Span::addNumber(int number)
{
	if (m_Data.size() == m_Data.capacity())
		throw(OutOfRangeException());

	m_Data.push_back(number);
	sort(m_Data.begin(), m_Data.end());
}

Span& Span::operator=(const Span& op)
{
	m_Data = op.m_Data;
	return *this;
}

int Span::operator[](unsigned int idx)
{
	if (idx < 0 || idx >= m_Data.size())
		throw(OutOfRangeException());

	return m_Data[idx];
}

const int Span::operator[](unsigned int idx) const
{
	if (idx < 0 || idx >= m_Data.size())
		throw(OutOfRangeException());

	return m_Data[idx];
}

