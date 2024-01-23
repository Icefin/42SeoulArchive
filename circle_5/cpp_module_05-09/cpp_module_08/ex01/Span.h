/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: singeonho <singeonho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:09 by singeonho         #+#    #+#             */
/*   Updated: 2024/01/23 15:43:29 by singeonho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <vector>
#include <exception>

class Span
{
public :
	class OutOfRangeException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

	class TooFewElementException : public std::exception
	{
	public :
		virtual const char* what() const throw();
	};

public :
	Span();
	Span(unsigned int N);
	Span(const Span& op);
	~Span();

	unsigned int size() const;

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void addNumber(int number);
	template<typename T>
	void addNumber(T begin, T end)
	{
		while (begin != end)
		{
			this->addNumber(*begin);
			begin++;
		}
	}

public :
	Span& operator=(const Span& op);
	int operator[](unsigned int idx);
	const int operator[](unsigned int idx) const;

private :
	std::vector<int> 	m_Data;
};

#endif